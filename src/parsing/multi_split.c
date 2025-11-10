/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaducurt <gaducurt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:11:07 by gaducurt          #+#    #+#             */
/*   Updated: 2025/11/10 16:47:05 by gaducurt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*free_all(char **tabf)
{
	int	i;

	i = 0;
	while (tabf[i])
	{
		free(tabf[i]);
		i++;
	}
	free(tabf);
	return (NULL);
}

static int	is_sep(char const s, char c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

static int	count_word(char const *s, unsigned char c1, unsigned char c2)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while ((s[i] && is_sep(s[i], c1)) || (s[i] && is_sep(s[i], c2)))
			i++;
		if ((s[i] && !is_sep(s[i], c1)) || (s[i] && !is_sep(s[i], c2)))
			count++;
		while ((s[i] && !is_sep(s[i], c1)) || (s[i] && !is_sep(s[i], c2)))
			i++;
	}
	return (count);
}

static char	**my_strdup(char **tabf, char const *s, int word, char c1, char c2)
{
	int	i;
	int	index;
	int	start;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && j < word)
	{
		index = 0;
		while ((s[i] && is_sep(s[i], c1)) || is_sep(s[i], c2))
			i++;
		start = i;
		while ((s[i] && !(is_sep(s[i], c1))) || (s[i] && !(is_sep(s[i], c2))))
			i++;
		tabf[j] = malloc(sizeof(char) * (i - start + 1));
		if (!tabf[j])
			return (free_all(tabf));
		while (start < i)
			tabf[j][index++] = s[start++];
		tabf[j][index] = '\0';
		j++;
	}
	return (tabf);
}

char	**multi_split(char const *s, char c1, char c2)
{
	char	**tabf;
	int		word;

	word = count_word(s, c1, c2);
	tabf = malloc(sizeof(char *) * (word + 1));
	if (!tabf)
		return (NULL);
	tabf = my_strdup(tabf, s, word, c1, c2);
	if (!tabf)
		return (NULL);
	tabf[word] = NULL;
	return (tabf);
}

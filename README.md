# miniRT

## Parsing
- Each line of file.rt is read by get_next_line and convert in an array char** with a multi_split().
- The datas of the arrays are stocked in a struct t_obj.
- We do an a array of struct with a struct vector.
- The vector is a struct for manage array automaticaly. It allocates the size of any type. When the vector->len is bigger than vector->capacity, it reallocates automaticaly vector->capacity * 2.

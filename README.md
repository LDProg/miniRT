# miniRT

This project has been created as part
of the 42 curriculum by <ludebion>, <gaducurt>

## Parsing

- Each line of file.rt is read by get_next_line and convert in an array char\*\* with a multi_split().
- The datas of the arrays are stocked in a struct t_objs.
- We do an a array of struct with a struct vector.
- The vector is a struct for manage array automaticaly. It allocates the size of any type. When the vector->len is bigger than vector->capacity, it reallocates automaticaly vector->capacity \* 2.

## Raytraycing

- If AA_SAMPLE = 1, one ray is launched per pixel.
- We search the intersection, for each ray.
- The equation of a ray is :
    O + dir * t
    O = Origin
    dir = direction
    t = ditance traveled by the ray (unknown)
- Once we have found t, we can compute the color with the norm and the light.
- If AA_SAMPLE = 4, we launch four rays per pixel (the pixel is split in four parts), calculate the color for each part and an average is obtained.
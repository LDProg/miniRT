# miniRT

*This project has been created as part
of the 42 curriculum by ludebion & gaducurt.*

## Description

The aim of this project is to creat a 3d rendering model using the raytracing technology. The principle is to simulate the reverse path of the light in reality.

### Parsing

- Each line of file.rt is read by get_next_line and convert in an array char\*\* with a multi_split().
- The datas of the arrays are stocked in a struct t_objs.
- We do an a array of struct with a struct vector.
- The vector is a struct for manage array automaticaly. It allocates the size of any type. When the vector->len is bigger than vector->capacity, it reallocates automaticaly vector->capacity \* 2.

### Raytraycing

- One ray is launched per pixel.
- We search the intersection, for each ray.
- The equation of a ray is :
	ray = O + dir * t
	O = Origin
	dir = direction
	t = ditance traveled by the ray (unknown)
- Whene a ray hits an object, a new ray is cast from the intersection to the light to check if there is an other object blocking it.
- Once we have found t, we can compute the color with the norm, the ambient light, the diffuse light and the object color.

## Instructions

### Prerequisites

- A Unix-based operating system (Linux or macOS)
- MinilibX graphics library

### Compilation

Clone the repository and compile the project :

```bash
git clone [your-repository-url]
cd miniRT
make
```

This will generate a miniRT executable.

### Execution

Run the program with a scene file as an argument :

```bash
./miniRT scenes/exemple.rt
```

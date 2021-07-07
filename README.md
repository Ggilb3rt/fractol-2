# Project fractol

## Summarry
This project use X11 custom library from 42, MLX.
You can show some fractals **mandelbrot, julia and burnship** in some sets of colors **basic, greyscale, monochrome, rainbow** and more.

# Submodule
```
git submodule init
git submodule update
```

## Compile
```
make
````

## Starting
```
./fractol [fractal_type] ([color]) (1)
```
Note : if no color mode provided, "basic" will be used
Note 2 : the last parameter (1) is only used to change the initiale value of c in Julia set

## Commands
List of commands to get lost in the infinity of fractal

1. **MOUSE SCROLL** : zoom in and out
1. **ARROWS** : go up, down, left, right
1. **s** : go to starting point ; _set screen axes to [-2, 2][-2, 2]_
1. **ESC** : quit

## Optimisations
Pour une optimisation maximum le programme ne calcule que les points visibles dans la fenêtre et limite le nombre d'itération de la suite à une valeur considérée comme acceptable *(valeur modifiable dans fractol.h)*.

Cependant une optimisation plus poussée pourrai être mise en place avec l'utilisation de multi-threads. Le sujet ne nous autorisant pas à utiliser de tels fonctions, je le ferai plus tard pour le plaisir.

😍
```
./fractol burnship rainbow
./fractol julia wtf\?
```
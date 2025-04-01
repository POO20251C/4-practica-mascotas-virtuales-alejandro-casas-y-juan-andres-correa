[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/_T9NCoa5)

# 4.-Pr-ctica-Mascotas-Virtuales


## Breve explicación

Este diseño es la estructura basica de un juego donde los usuarios pueden adoptar mascotas virtuales, darles habilidades y cuidarlas.

### Clases

* **PixelPets** es como el "mundo" del juego. Aquí se guardan los usuarios, los objetos y las habilidades disponibles. También tiene funciones para agregar usuarios y objetos.
* **Usuario** representa a cada persona que juega. Cada usuario tiene una lista de mascotas y puede adoptar nuevas.
* **Mascota** Tiene un nombre, energía, salud y edad. Además, puede tener habilidades y recibir cuidados. También puede usar objetos para mejorar su estado.
* **Habilidad** Son acciones que pueden realizar, como "saltar" o "curarse", pero consumen energía.
* **Cuidado** es como el historial de atención de la mascota, registrando cuándo y cómo ha sido cuidada.
* **Objeto** son cosas que se pueden usar en las mascotas, como comida o medicina, y afectan su energía y salud.

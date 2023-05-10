# 42Cub3d
![school_42](https://user-images.githubusercontent.com/94384240/170144677-24ff4d41-6e4a-491a-adfa-7dcf0eac630a.jpeg)

42 Cursus Cub3D

This is the last project in C at 42. The goal was to recreate a basic raycaster with Wolfenstein 3D as a reference.
It was a group project.
I handled the Raycasting and graphic part, and [mtavares](https://github.com/mtavares98) the parsing.
We completed the project in about 2 months.  
We used the original textures of Wolfenstein.
The trickiest part for me, was to figure out how to put the X value of a texture into a Wall.

# Gallery
![Screenshot 2023-05-10 013326](https://github.com/jlebre/42Cub3d/assets/94384240/9f3cc16c-c1b0-47a7-9753-5d153b9ed2ac)

![Screenshot 2023-05-10 013357](https://github.com/jlebre/42Cub3d/assets/94384240/4c02b616-5d12-4026-8d53-98fb92f44621)

https://github.com/jlebre/42Cub3d/assets/94384240/6084f44a-c4c4-429c-b9b1-3fb7c150e839

https://github.com/jlebre/42Cub3d/assets/94384240/bcba92b7-983e-44a1-a111-9cd4b3bd9840

# Installation
```
git clone https://github.com/jlebre/42Cub3d.git
cd 42Cub3d/
make a
```
# The Assignment
To make a labrinth in 3D with first person view like Wolfenstein 3D.

As per the Subject:

> The constraints are as follows:    
> - You must use the miniLibX. Either the version that is available on the operating  
> system, or from its sources. If you choose to work with the sources, you will  
> need to apply the same rules for your libft as those written above in Common  
> Instructions part.
> >
> - The management of your window must remain smooth: changing to another window, minimizing, etc.  
> 
> - Display different wall textures (the choice is yours) that vary depending on which  
> side the wall is facing (North, South, East, West).  
> 
> - Your program must be able to set the floor and ceiling colors to two different ones. 
>  
> - The program displays the image in a window and respects the following rules:  
>   - The left and right arrow keys of the keyboard must allow you to look left and  
> right in the maze.  
> 
>   - The W, A, S, and D keys must allow you to move the point of view through  
>   the maze.
>
>   - Pressing ESC must close the window and quit the program cleanly.
>
>   - Clicking on the red cross on the window’s frame must close the window and  
>   quit the program cleanly.
>
>   - The use of images of the minilibX is strongly recommended.
>
> - Your program must take as a first argument a scene description file with the .cub  
> extension.  
>   - The map must be composed of only 6 possible characters: 0 for an empty space,  
>   1 for a wall, and N,S,E or W for the player’s start position and spawning  
>   orientation.  
>   This is a simple valid map:   
>     ```
>     111111  
>     100101  
>     101001  
>     1100N1  
>     111111
>     ```
> 
>   - The map must be closed/surrounded by walls, if not the program must return  
>   an error.
>   
>   - Except for the map content, each type of element can be separated by one or  
>   more empty line(s).
>   
>   - Except for the map content which always has to be the last, each type of  
>   element can be set in any order in the file.
>   
>   - Except for the map, each type of information from an element can be separated  
>   by one or more space(s).
>   
>   - The map must be parsed as it looks in the file. Spaces are a valid part of the  
>   map and are up to you to handle. You must be able to parse any kind of map,  
>   as long as it respects the rules of the map.
>   
>   - Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), >followed by all specific informations for each
>object in a strict order such as :
>
>     - North texture:  
>     ```
>     NO ./path_to_the_north_texture
>     ```
>       - identifier: NO  
>       - path to the north texure
>       
>     - South texture:  
>     ```
>     SO ./path_to_the_south_texture
>     ```
>       - identifier: SO  
>       - path to the south texure
>       
>     - West texture:  
>     ```
>     WE ./path_to_the_west_texture
>     ```
>       - identifier: WE  
>       - path to the west texure
>       
>     - East texture:  
>     ```
>     EA ./path_to_the_east_texture
>     ```
>       - identifier: EA  
>       - path to the east texure
>       
>     - Floor color:  
>     ```
>     F 220,100,0
>     ```
>       - identifier: F  
>       - R,G,B colors in range [0,255]: 0, 255, 255
>       
>      - Ceiling color:
>      ```
>      C 225,30,0
>      ```
>       - identifier: C  
>       - R,G,B colors in range [0,255]: 0, 255, 255
>       
>   - Example of the mandatory part with a minimalist .cub scene:  
>   ```
>   NO ./path_to_the_north_texture  
>   SO ./path_to_the_south_texture  
>   WE ./path_to_the_west_texture  
>   EA ./path_to_the_east_texture
>   
>   F 220,100,0  
>   C 225,30,0  
>   
>           1111111111111111111111111  
>           1000000000110000000000001  
>           1011000001110000000000001  
>           1001000000000000000000001  
>   111111111011000001110000000000001  
>   100000000011000001110111111111111  
>   11110111111111011100000010001  
>   11110111111111011101010010001  
>   11000000110101011100000010001  
>   10000000000000001100000010001  
>   10000000000000001101010010001  
>   11000001110101011111011110N0111  
>   11110111 1110101 101111010001  
>   11111111 1111111 111111111111  
>   ```
>   
>   - If any misconfiguration of any kind is encountered in the file, the program  
>   must exit properly and return "Error\n" followed by an explicit error message  
>   of your choice.
>   

# Features
- A working compass

- FOV in Minimap corresponds to the actual Field Of Vision of the player

- "P" for pause menu.

- "M" to hide / show the Minimap


We were going to add enemies, so we implemented a lives system.  
If you press "-" you'll lose a life. When it reaches 0 the program stops.

The settings icon is not working.

# The Code Explained

# Conclusion
I really enjoyed this assignment! It was fun, and it is good to have something progressing visually.

Maybe my favorite project until now.

The final grade was 115, as we also completed 3 of the 5 bonuses:

- Wall Colisions

- Mini Map System

- Move FOV With Mouse

![Screenshot 2023-05-09 233645](https://github.com/jlebre/42Cub3d/assets/94384240/475636ea-68f0-4c38-95ac-b007bd2d68fd)

Maybe sometime i'll add more things to the game.

# Minecraft_2.0
Minecraft in C++ 2.0 by YT: Tim Stellar

***
En: 
First, download project by clicking `Code->Download ZIP` or `Open in Visual Studio` or `Open in GitHub Desktop`.
After that, you can open this project by opening `.sln` file in Visual Studio.
Next step, you need to download [GLAD](https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D4.6&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=core&loader=on) (click generate only!!!), [GLFW](https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.WIN32.zip), [stb-master](https://github.com/nothings/stb.git) and [glm](https://github.com/g-truc/glm.git).
The last step to run project is go to `Project->Properties` in VS and change path to your libs `C/C++->General->Additional Include Directories`. File glad.c (src folder in glad lib) move to main folder with other files. If you have an error while running program, check in Configuration manager 'platform' section. It must be x32.
That's all! Enjoy!

***
Ru:
Первым делом, скачайте проект. Для этого нажмите на кнопку вверху и выберите `Code->Download ZIP` или `Open in Visual Studio` or `Open in GitHub Desktop`.
После этого откройте `.sln` файл в Visual Studio.
Затем скачайте [GLAD](https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D4.6&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=core&loader=on) (только нажать кнопку generate!!!), [GLFW](https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.WIN32.zip), [stb-master](https://github.com/nothings/stb.git) и [glm](https://github.com/g-truc/glm.git).
Последнее, что вам нужно сделать, это скорректировать пути к скачанным библиотекам. Для этого перейдите в `Project->Properties` в VS и зайдите пройдите по пути `C/C++->General->Additional Include Directories`. Файл glad.c (папка src в библиотеке glad) перетащить в основную директорию со всеми файлами. Если появляется ошибка при запуске, проверьте в Configuration manager значение 'platform', оно должно быть x32.
Это всё! Удачного использования!
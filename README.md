# bmp2csv
Convert imagefile(.bmp) to textfile(.csv, .text)

# How to use
1. compile
```
$ gcc main.c bitmap.c
```

1. run
```
$ ./a.out InputImageName.bmp OutputTextName.txt
```

# Change max image size
In main.c line5, 6
```c:main.c
#define MAX_WIDTH 128
#define MAX_HEIGHT 128
```
change here

#Reference
[Bitmapファイルを入出力してみる - [物理のかぎしっぽ]](http://hooktail.org/computer/index.php?Bitmap%A5%D5%A5%A1%A5%A4%A5%EB%A4%F2%C6%FE%BD%D0%CE%CF%A4%B7%A4%C6%A4%DF%A4%EB)

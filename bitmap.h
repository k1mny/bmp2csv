#ifndef __BITMAP_H_INCLUDED__
#define __BITMAP_H_INCLUDED__

#define FILEHEADERSIZE 14					//•’•°•§•Î•ÿ•√•¿§Œ•µ•§•∫
#define INFOHEADERSIZE 40					//æ Û•ÿ•√•¿§Œ•µ•§•∫
#define HEADERSIZE (FILEHEADERSIZE+INFOHEADERSIZE)

typedef struct{
	unsigned char b;
	unsigned char g;
	unsigned char r;
}Rgb;

typedef struct{
	unsigned int height;
	unsigned int width;
	Rgb *data;
}Image;

//ºË∆¿§À¿Æ∏˘§π§Ï§–•›•§•Û•ø§Úº∫«‘§π§Ï§–NULL§Ú ÷§π
Image *Read_Bmp(char *filename);

//ΩÒ§≠π˛§ﬂ§À¿Æ∏˘§π§Ï§–0§Úº∫«‘§π§Ï§–1§Ú ÷§π
int Write_Bmp(char *filename, Image *img);

//Image§Ú∫Ó¿Æ§∑°¢RGBæ Û§‚width*height ¨§¿§±∆∞≈™§ÀºË∆¿§π§Î°£
//¿Æ∏˘§π§Ï§–•›•§•Û•ø§Ú°¢º∫«‘§π§Ï§–NULL§Ú ÷§π
Image *Create_Image(int width, int height);
//Image§Ú≤ÚÀ°§π§Î
void Free_Image(Image *img);

#endif /*__BITMAP_H_INCLUDED__*/

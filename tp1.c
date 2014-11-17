
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction_Tp1.h"


//===========================================================================
//                             Definition of the structure
//===========================================================================

struct my_struct 
{
 int width;
 int height;
 u_char* data;
} ;


//============================================================================
//                                  Main
//============================================================================
int main(int argc, char* argv[])
{

//-------------------------------------------------------------------------------
//Initialization of the structure
//------------------------------------------------------------------------------

 struct my_struct image;
 image.data = NULL;

//--------------------------------------------------------------------------
// Read file "gargouille.ppm" into image (width and height)
//--------------------------------------------------------------------------
  FILE* ppm_input;
  char* fichier = "gargouille.ppm";
  ppm_read_from_file(&image.width, &image.height, &image.data,ppm_input, fichier);




//-------------------------------------------------------------------------------
//Initialization of the structure
//------------------------------------------------------------------------------
 struct my_struct image_bw;
 image_bw.width = image.width;
 image_bw.height = image.height;
 image_bw.data = (u_char*) malloc(3 * image_bw.width * image_bw.height * sizeof(*(image_bw.data)));

  //--------------------------------------------------------------------------
  // Create a desaturated (B&W) copy of the image we've just read and
  // write it into "gargouille_BW.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_bw

 memcpy(image_bw.data, image.data, 3 * image_bw.width * image_bw.height * sizeof(*(image_bw.data)));


  // Desaturate image_bw
  ppm_desaturate(image_bw.data, image_bw.width, image_bw.height);

  // Write the desaturated image into "gargouille_BW.ppm"
  FILE* ppm_output;
  char* fichier1 = "gargouille_BW.ppm";
  ppm_write_to_file(image_bw.width, image_bw.height, image_bw.data, ppm_output,  fichier1);
  //fclose(ppm_output);

  // Free the desaturated image
  free(image_bw.data);




//-------------------------------------------------------------------------------
//Initialization of the structure
//------------------------------------------------------------------------------
 struct my_struct small_image;
 small_image.width = image.width;
 small_image.height = image.height;
 small_image.data = (u_char*) malloc(3 *small_image.width * small_image.height * sizeof(*(small_image.data)));


  //--------------------------------------------------------------------------
  // Create a resized copy of the image and
  // write it into "gargouille_small.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_small
  
  memcpy(small_image.data, image.data , 3 * small_image.width * small_image.height * sizeof(*(small_image.data)));

  // Shrink image_small size 2-fold
  ppm_shrink(&small_image.data, &small_image.width,&small_image.height, 2);

  // Write the desaturated image into "gargouille_small.ppm"
  //ppm_output = fopen("gargouille_small.ppm", "wb");
  char* fichier3= "gargouille_small.ppm";
  ppm_write_to_file(small_image.width,small_image.height, small_image.data, ppm_output, fichier3);
  //fclose(ppm_output);

  // Free the not yet freed images
  free(image.data);
  free(small_image.data);

  return 0;
}













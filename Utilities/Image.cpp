#include "Image.hpp"

#include <iostream>
#include <chrono>
#include <png++/png.hpp>
#include <jpeglib.h>

#include "World.hpp"

Image::Image(void)
    : hres(0),
    vres(0),
    raw_image()
{
}

Image::~Image(void) {
    raw_image.clear();
}

void Image::set_resolution(const int h, const int v) {
    hres = h;
    vres = v;
    raw_image.reserve(hres * vres);
}

void Image::set_pixel(RGBColor c) {
    c.to_255(); // from 0-1 to 0-255 for png::image
    raw_image.push_back(c);
}

void Image::set_pixel(RGBColor c, [[maybe_unused]] int x, [[maybe_unused]] int y) {
    c.to_255(); // from 0-1 to 0-255 for png::image
    raw_image.push_back(c);
}

void Image::save_image(int type) {
    switch (type) {
    case FILE_BMP:
        // save_image_bmp();
        break;
    case FILE_PNG:
        save_image_png();
        break;
    case FILE_JPEG:
        save_image_jpeg();
        break;
    default:
        save_image_bmp();
    }
}

void Image::save_image_bmp() {
}

void Image::save_image_png() {
    png::image<png::rgb_pixel> image(hres, vres);
    int i = 0;

    for (int r = 0; r < vres; r++)
        for (int c = 0; c < hres; c++, i++) {
            int x = c;
            int y = vres - r - 1;
            image[y][x] = png::rgb_pixel(raw_image[i].r,
                                         raw_image[i].g,
                                         raw_image[i].b);
        }

    using namespace std::chrono;
    auto UTC = duration_cast<seconds>((system_clock::now()).time_since_epoch()).count();
    // std::string filename = "/mnt/d/w/rt_image/" + std::to_string(UTC);
    std::string filename = "../Images/" + std::to_string(UTC);
    image.write(filename + ".png");
    std::cout << std::endl; // jump after progress bar
    std::cout << "Image: " << filename << ".png" << std::endl;
    // copy in current folder
    filename = "./result";
    image.write(filename + ".png");
    std::cout << "Image: " << filename << ".png" << std::endl;
}

// void World::saveJPEG(const char * filename2, uint8_t * raw) const;
void Image::save_image_jpeg() {
//     uint8_t *raw = (uint8_t*) malloc(sizeof(uint8_t) * hres * vres * 3);
//     uint8_t *save = raw;
//     struct jpeg_compress_struct cinfo;
//     struct jpeg_error_mgr jerr;

//     jpeg_create_compress(&cinfo);
//     cinfo.err = jpeg_std_error(&jerr);

//     FILE *fp = fopen(filename2, "wb");
//     if (fp == NULL)
//         printf("Error: failed to open %s\n", filename2);

//     jpeg_stdio_dest(&cinfo, fp);
//     cinfo.image_width       = vp.hres;
//     cinfo.image_height      = vp.vres;
//     cinfo.input_components  = 3;     // # of color components per pixel
//     cinfo.in_color_space    = JCS_RGB; // colorspace of input image
//     jpeg_set_defaults(&cinfo);

//     // compression
//     cinfo.dct_method = JDCT_ISLOW;
//     int quality = 100; // 0 - 100 range
//     jpeg_set_quality(&cinfo, quality, TRUE);
//     jpeg_start_compress(&cinfo, TRUE);

//     uint8_t *row_ptr = raw;
//     const uint32_t row_stride = vp.hres * 3;
//     for (int y = 0; y < vp.hres; y++) {
//         jpeg_write_scanlines(&cinfo, &row_ptr, 1);
//         row_ptr += row_stride;
//     }
//     jpeg_finish_compress(&cinfo);
//     jpeg_destroy_compress(&cinfo);
//     fclose(fp);

//     // Some data is allocated "permanently" and will not be freed until the JPEG
//     // object is destroyed.  Most data is allocated "per image" and is freed by
//     // jpeg_finish_compress, jpeg_finish_decompress, or jpeg_abort.  You can call the
//     // memory manager yourself to allocate structures that will automatically be
//     // freed at these times.  Typical code for this is
//     //   ptr = (*cinfo->mem->alloc_small) ((j_common_ptr)cinfo, JPOOL_IMAGE, size);
//     // Use JPOOL_PERMANENT to get storage that lasts as long as the JPEG object.
//     // Use alloc_large instead of alloc_small for anything bigger than a few Kbytes.
//     // There are also alloc_sarray and alloc_barray routines that automatically
//     // build 2-D sample or block arrays.
}

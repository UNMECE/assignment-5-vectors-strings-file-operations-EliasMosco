
struct _pixel
{
  float r;
  float g;
  float b;
  int x;
  int y;
};
typedef struct _pixel Pixel;
void average_colors(std::vector<Pixel> &pixel_list);
void flip_vertically(std::vector<Pixel> &pixel_list);

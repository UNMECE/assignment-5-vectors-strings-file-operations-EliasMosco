#include<iostream>
#include<fstream>
#include "pixel.h"
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<Pixel> pixel_list;
/*
*    
*    find the position of the next ',', make that position
*    int first_position = string.start;
*    for(i=0; i < string.length(); i++){
*    
*    string substring;
*    The_second_position = string.find("\n");
*    substring = string.substr(first_position, The_second_position);
*    int first_sub_position = string.start;
*    for(j=0; j < substring.length(); j++){

*    The_second_sub_position = string.find(",");
*    substring = string.substr(first_position, second_position);
*    //first position = second position
*    int pixel.x = substring 1;
*    int pixel.y = substring 2;
*    float Pixel.r = substring 3;
*    float Pixel.y = substring 3;
*    float Pixel.z = substring 3;
*    }
*  }
*    
*/
#define MAX_X_LENGTH 512
#define MAX_Y_LENGTH 256
#define TOTAL_PIXELS 131072
void average_colors(std::vector<Pixel> &pixel_list){
    int r_avg, g_avg, b_avg;
    for(int i = 0; i < pixel_list.size(); i++){
    r_avg += pixel_list.at(i).r;
    g_avg += pixel_list.at(i).g;
    b_avg += pixel_list.at(i).b;
    }
    r_avg/= pixel_list.size();
    cout << "the average of r is " << r_avg << endl;
    g_avg/= pixel_list.size();
    cout << "the average of r is " << g_avg << endl;
    b_avg/= pixel_list.size();
    cout << "the average of r is " << b_avg << endl;
}
bool CompareYHelper(const Pixel& a, const Pixel& b){
     return a.y < b.y;
}
void flip_vertically(std::vector<Pixel> &pixel_list){
    sort(pixel_list.begin(),pixel_list.end(), CompareYHelper);
    int max = pixel_list.back().y;
    for(auto& Pixel : pixel_list){
        Pixel.y = max - Pixel.y;
    }
}
int main(){
     ifstream inputFile("pixels.dat");
    string str;

    char* end;
     while (getline(inputFile, str)) {   
    string substring;
   int first_sub_position = 0;
   Pixel pixel_to_push;
    for(int j=0; j < substring.length(); j++){

    int The_second_sub_position = substring.find(",");
    string pixel_substring = substring.substr(first_sub_position, The_second_sub_position);
    first_sub_position = The_second_sub_position;

    //first position = second position
    switch (j)
    {
    case 0:
        pixel_to_push.x = stod(pixel_substring);
        break;
    case 1:
        pixel_to_push.y = stod(pixel_substring);
        break;
    case 2:
        pixel_to_push.r = stof(pixel_substring);
        break;
    case 3:
        pixel_to_push.g = stof(pixel_substring);
        break;
    case 4:
        pixel_to_push.b = stof(pixel_substring);
        break;
    
    default:
        break;
    }
    
    }
    pixel_list.push_back(pixel_to_push);
  }
  inputFile.close();
  average_colors(pixel_list);
  flip_vertically(pixel_list);
  ofstream outPutFile("flipped.dat");
  for (const auto &pixel : pixel_list) {
        outPutFile << pixel.x << "," << pixel.y << ","
                    << pixel.r << "," << pixel.g << "," << pixel.b << "\n";
    }

    outPutFile.close();
}
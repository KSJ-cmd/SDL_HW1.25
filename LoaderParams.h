#ifndef __LOADERPARAMS_H__
#define __LOADERPARAMS_H__

#include<iostream>
class LoaderParams{
public:
  LoaderParams(int x, int y, int width,int height, std::string textureID)
    :m_x(x),m_y(y),m_width(width),m_height(height)
    ,m_textureID(textureID){}
  int getX() const {return m_x;}
  int getY() const {return m_y;}
  int getWidth() const {return m_width;}
  int getHeight() const {return m_height;}
  std::string getTextureID() const {return m_textureID;}
private:
  int m_x = 0;
  int m_y = 0;
  int m_width = 0;
  int m_height = 0;

  std::string m_textureID = "";

};
#endif 
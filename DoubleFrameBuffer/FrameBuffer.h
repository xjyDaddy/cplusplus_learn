//Date:2018/5/29
//Author:dylan_xi
//Desc: Frame Buffer
const char WHITE = 0;
const char BLACK = 1;
class FrameBuffer
{
public:
    FrameBuffer(){};
    void clear()
    {
        for(int i = 0; i < WIDTH*HEIGHT; i++)
        {
            _pixels[i] = WHITE;
        }
    }
    void draw(int x , int y)
    {
        _pixels[(WIDTH*y)+x] = BLACK;
    }
    //expose the raw array of memory holding the pixel,
    //the video driver will call the function frequently to stream memory
    //from the buffer onto the screen
    const char* getPixels()
    {
        return _pixels;
    }
private:
    static const int WIDTH = 160;  
    static const int HEIGHT = 120;
    char _pixels[WIDTH*HEIGHT];
};
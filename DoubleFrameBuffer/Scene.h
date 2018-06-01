//Date:2018/5/29
//Author:dylan_xi
//Desc: Scene
#include"FrameBuffer.h"
class Scene
{
public:
    Scene():
        _currentBuffer(&_buffers[0]),
        _nextBuffer(&_buffers[1])
        {};
    void draw()
    {
        _nextBuffer->clear();
    
        _nextBuffer->draw(1,2);
        _nextBuffer->draw(3,3);
        _nextBuffer->draw(4,7);
        //... lots of draw called 
        _nextBuffer->draw(9,2);

        swapBuffer();
    }
    FrameBuffer& getBuffer() const {return *_currentBuffer;}

private:
    void swapBuffer(){
        FrameBuffer* tempBuffer = _currentBuffer;
        _currentBuffer = _nextBuffer;
        _nextBuffer = tempBuffer;
    }
    FrameBuffer _buffers[2];
    FrameBuffer* _currentBuffer;
    FrameBuffer* _nextBuffer;
};
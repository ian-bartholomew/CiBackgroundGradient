#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Vbo.h"
#include "CiBackgroundGradient.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BackgroundGradientApp : public AppNative {
public:
    void setup();
    void draw();
    void resize();
    
    gl::VboMeshRef mVboMeshRef;
    
    Color mStart, mStop;
};

void BackgroundGradientApp::setup()
{
    mStart = ColorA::white();
    mStop = ColorA::black();
    
    mVboMeshRef = bggradient::BackgroundGradient::buildGradient(mStart, mStop, getWindowWidth(), getWindowHeight());
    
}

void BackgroundGradientApp::draw()
{
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) );
    
    // draw vbo mesh
    gl::draw(mVboMeshRef);
}

void BackgroundGradientApp::resize()
{
    mVboMeshRef = bggradient::BackgroundGradient::buildGradient(mStart, mStop, getWindowWidth(), getWindowHeight());
}

CINDER_APP_NATIVE( BackgroundGradientApp, RendererGl )

precision highp float;
 precision highp int;
 uniform mat4 CC_PMatrix;
 uniform mat4 CC_MVMatrix;
 uniform mat4 CC_MVPMatrix;
 uniform mat3 CC_NormalMatrix;
 uniform vec4 CC_Time;
 uniform vec4 CC_SinTime;
 uniform vec4 CC_CosTime;
 uniform vec4 CC_Random01;
 uniform sampler2D CC_Texture0;
 uniform sampler2D CC_Texture1;
 uniform sampler2D CC_Texture2;
 uniform sampler2D CC_Texture3;
 //CC INCLUDES END


attribute vec4 a_position;
attribute vec2 a_texCoord;
varying vec2 v_texCoord;
void main() {
  gl_Position = a_position;
  v_texCoord = a_texCoord;
}

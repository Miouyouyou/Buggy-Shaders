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


varying vec2 v_texCoord;
uniform sampler2D texture0;
void main() {
  vec4 color = texture2D(texture0, v_texCoord);
  color.rgb *= color.w;
  color.a = 1.0;
 gl_FragColor = color;
}

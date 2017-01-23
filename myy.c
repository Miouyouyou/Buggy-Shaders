#include <GLES2/gl2.h>
#include <helpers/base_gl.h>
#include <helpers/struct.h>
#include <helpers/log.h>

#include <myy.h>

void myy_init() {}

void myy_display_initialised(unsigned int width, unsigned int height) {}

void myy_generate_new_state() {}

enum shader_attribs { attr_a_position, attr_a_texCoords };

void myy_init_drawing() {
  GLuint program =
    glhSetupAndUse("shaders/standard.vert", "shaders/standard.frag",
                   2 /* attributes */,
                   "a_position\0"
                   "a_texCoord\0");
  GLuint texid;
  glhUploadTextures("textures/cards.raw\0", 1, &texid);
  glUniform1i(glGetUniformLocation(program, "texture0"), GL_TEXTURE0);
  glEnableVertexAttribArray(attr_a_position);
  glEnableVertexAttribArray(attr_a_texCoords);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

#define myy_w_dim 1.0f
#define myy_layer 0.5f

#define myy_left  -0.06796875f
#define myy_right  0.06796875f
#define myy_up     0.1875f
#define myy_down  -0.1875f

#define half_texel_w  (1/2784.0f)
#define half_texel_h  (1/1080.0f)
#define myy_tex_left  (0.0625f+half_texel_w)
#define myy_tex_right (0.125f-half_texel_w)
#define myy_tex_up    (0.25f-half_texel_h)
#define myy_tex_down  (0.0f+half_texel_h)

GLfloat quad[] = {
   myy_left,  myy_up,   myy_layer, myy_w_dim, myy_tex_left,  myy_tex_up,
   myy_right, myy_up,   myy_layer, myy_w_dim, myy_tex_right, myy_tex_up,
   myy_right, myy_down, myy_layer, myy_w_dim, myy_tex_right, myy_tex_down,
   myy_left,  myy_down, myy_layer, myy_w_dim, myy_tex_left,  myy_tex_down 
};

void myy_draw() {
  glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
  glClearColor(0.3f, 0.2f, 0.5f, 1.0f);
  glVertexAttribPointer(attr_a_position, 4, GL_FLOAT, GL_FALSE,
                        6 * sizeof(float), quad);
  glVertexAttribPointer(attr_a_texCoords, 2, GL_FLOAT, GL_FALSE,
                        6 * sizeof(float), quad+4);
  glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void myy_save_state(struct myy_game_state * const state) {}

void myy_resume_state(struct myy_game_state * const state) {}

void myy_cleanup_drawing() {}

void myy_stop() {}

void myy_click(int x, int y, unsigned int button) {}
void myy_doubleclick(int x, int y, unsigned int button) {}
void myy_move(int x, int y) {}
void myy_hover(int x, int y) {}
void myy_key(unsigned int keycode) {}


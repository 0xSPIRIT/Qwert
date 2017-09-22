#pragma once
#include <SDL.h>
#include <iostream>

#include "../maths/vec2.h"
#include "../main/Variables.h"

#define MOUSE_LEFT 1
#define MOUSE_MIDDLE 2
#define MOUSE_RIGHT 3

struct Input {
	Input() : pos(0, 0) {};

	bool isKeyPressed(const SDL_Scancode& code);
	bool isKeyReleased(const SDL_Keycode& code);
	bool pressed = false;

	bool isMousePressed(int button);

	void setEvent(SDL_Event* event) { this->event = event; }

	const vec2& getMousePos();

	Direction GRAVITY_DIRECTION = Direction::Down;
private:
	vec2i pos;
	SDL_Event* event;

};

enum Keys {
	KEY_BACKSPACE = 8,
	KEY_TAB = 9,
	KEY_ENTER = 13,
	KEY_SHIFT = 14,
	KEY_ESCAPE = 27,
	
	KEY_SPACE = 32,
	KEY_EXCLAMATION,
	KEY_DOUBLEQUOTE,
	KEY_POUND,
	KEY_DOLLAR,
	KEY_PERCENT,
	KEY_AMPERSAND,
	KEY_SINGLEQUOTE,
	KEY_LEFTPARENTHESIS,
	KEY_RIGHTPARENTHESIS,
	KEY_ASTERISK,
	KEY_PLUS,
	KEY_COMMA,
	KEY_MINUS,
	KEY_PERIOD,
	KEY_SLASH,
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_COLON,
	KEY_SEMICOLON,
	KEY_LESSTHAN,
	KEY_GREATERTHAN,
	KEY_QUESTIONMARK,
	KEY_AT,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_LEFTSQUAREBRACKET,
	KEY_BACKSLASH,
	KEY_RIGHTSQUAREBRACKET,
	KEY_CARET,
	KEY_UNDERSCORE,
	KEY_ACCENT,
	KEY_a,
	KEY_b,
	KEY_c,
	KEY_d,
	KEY_e,
	KEY_f,
	KEY_g,
	KEY_h,
	KEY_i,
	KEY_j,
	KEY_k,
	KEY_l,
	KEY_m,
	KEY_n,
	KEY_o,
	KEY_p,
	KEY_q,
	KEY_r,
	KEY_s,
	KEY_t,
	KEY_u,
	KEY_v,
	KEY_w,
	KEY_x,
	KEY_y,
	KEY_z,
	KEY_LEFTCURLYBRACKET,
	KEY_VERTICALBAR,
	KEY_RIGHTCURLYBRACKET,
	KEY_TILDE,
	KEY_DELETE
};
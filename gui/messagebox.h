#ifndef gui_messagebox_h
#define gui_messagebox_h

#include "gui_frame.h"
#include "components/gui_location_view_t.h"
#include "components/gui_image.h"
#include "components/gui_fixedwidth_textarea.h"
#include "../simcolor.h"
#include "../utils/cbuffer_t.h"

/**
 * A class for Message/news window.
 * @author Hj. Malthaner
 */
class news_window : public gui_frame_t
{
public:
	virtual PLAYER_COLOR_VAL get_titlecolor() const { return color; }

	// Knightly : to extend the window with an extra component in the upper right corner
	void extend_window_with_component(gui_component_t *const component, const scr_size size, const scr_coord offset = scr_coord(0,0));

protected:
	news_window(const char* text, PLAYER_COLOR_VAL color);

private:
	cbuffer_t buf;
	gui_fixedwidth_textarea_t textarea;
	PLAYER_COLOR_VAL color;
};


/* Shows a news window with an image */
class news_img : public news_window
{
public:
	news_img(const char* text);
	news_img(const char* text, image_id image, PLAYER_COLOR_VAL color=WIN_TITLE);

private:
	void init(image_id image);
	gui_image_t image;
};


/* Shows a news window with a view on some location */
class news_loc : public news_window
{
public:
	news_loc(const char* text, koord k, PLAYER_COLOR_VAL color = WIN_TITLE);

	void map_rotate90( sint16 new_ysize );

	virtual koord3d get_weltpos(bool);

private:
	location_view_t view;
};

#endif

#ifndef VFD_H_
#define VFD_H_

#define ICON_ON  1
#define ICON_OFF 0

//#if !defined (ENABLE_FORTIS_HDBOX)
typedef enum { USB = 0x10, HD, HDD, LOCK, BT, MP3, MUSIC, DD, MAIL, MUTE, PLAY, PAUSE, FF, FR, REC, CLOCK } tvfd_icon;
typedef enum { RED_LED = 0, GREEN_LED } tvfd_led;
//#else
//typedef enum { USB = 1, I_STANDBY, I_SAT, I_REC, I_TIMESHIFT, I_TIMER, I_HD, I_LOCK, I_DD, I_MUTE, I_TUNER1, I_TUNER2, I_MP3, I_REPEAT,
//               I_PLAY, I_PAUSE, I_TER, I_FILE_, I_480i, I_480p, I_576i, I_576p, I_720p, I_1080i, I_1080p } tvfd_icon;
//typedef enum { RED_LED = 0, BLUE_LED, CROSS_UP, CROSS_LEFT, CROSS_RIGHT, CROSS_DOWN } tvfd_led;
//#endif

class evfd
{
protected:
	static evfd *instance;
	int file_vfd;
	int vfd_type;
#ifdef SWIG
	evfd();
	~evfd();
#endif
public:
#ifndef SWIG
	evfd();
	~evfd();
#endif
	void init();
	static evfd* getInstance();

	int getVfdType() { return vfd_type; }
	void vfd_set_SCROLL(int id);
	void vfd_set_CENTER(bool id);
	void vfd_set_icon(int id, bool onoff);
	void vfd_set_icon(int id, bool onoff, bool force);
	void vfd_set_led(tvfd_led id, int onoff);
	void vfd_clear_icons();

	void vfd_write_string(char * string);
	void vfd_write_string(char * str, bool force);
	void vfd_write_string_scrollText(char* text);
	void vfd_clear_string();

	void vfd_set_brightness(unsigned int setting);
	void vfd_set_light(bool onoff);
	void vfd_set_fan(bool onoff);
};

#endif

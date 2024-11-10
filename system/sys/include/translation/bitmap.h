#ifndef __F_TRANSLATION_BITMAP_H__
#define __F_TRANSLATION_BITMAP_H__

namespace os
{
	  
class TranslatorBitmap
{
public:
	enum
	{
    	BMF_MULTIPASS = 0x0001
	};
	struct BitmapHeader
	{
    	size_t	bh_header_size;
    	size_t	bh_data_size;
    	uint32	bh_flags;
    	IRect	bh_bounds;
    	int		bh_frame_count;
    	int		bh_bytes_per_row;
    	color_space bh_color_space;
	};

	struct BitmapFrameHeader
	{
    	size_t 	bf_header_size;
    	size_t 	bf_data_size;
    	uint32  	bf_time_stamp;
    	color_space bf_color_space;
    	int		bf_bytes_per_row;
    	IRect	bf_frame;
	};
};
}


#endif


#pragma once

#include "image_function.h"

// Utilize these image functions only if your CPU supports AXV 2.0 !!!

// These functions contain AXV 2.0 code through Intel Intrinsics functions
// Functions have totally same results like normal functions but they are faster!
// You will have a speed up compare to normal functions if a width of inspection area is bigger than 32 pixels
// because 32 pixels is minimum width what AVX 2.0 function can process
// Anyway you do not need to care about this. Everything is done inside. Just use it if you want to have faster code

// Remember to include all necessary files for SSE too!

namespace Image_Function_Avx
{
	using namespace Bitmap_Image;

	Image BitwiseAnd( const Image & in1, const Image & in2 );
	void  BitwiseAnd( const Image & in1, const Image & in2, Image & out );
	Image BitwiseAnd( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  uint32_t width, uint32_t height );
	void  BitwiseAnd( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );	

	Image BitwiseOr( const Image & in1, const Image & in2 );
	void  BitwiseOr( const Image & in1, const Image & in2, Image & out );
	Image BitwiseOr( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					 uint32_t width, uint32_t height );
	void  BitwiseOr( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					 Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );	

	Image BitwiseXor( const Image & in1, const Image & in2 );
	void  BitwiseXor( const Image & in1, const Image & in2, Image & out );
	Image BitwiseXor( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  uint32_t width, uint32_t height );
	void  BitwiseXor( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	// Invert function is Bitwise NOT operation. But to make function name more user-friendly we named it like this
	Image Invert( const Image & in );
	void  Invert( const Image & in, Image & out );
	Image Invert( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height );
	void  Invert( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
				  uint32_t width, uint32_t height );

	Image Maximum( const Image & in1, const Image & in2 );
	void  Maximum( const Image & in1, const Image & in2, Image & out );
	Image Maximum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   uint32_t width, uint32_t height );
	void  Maximum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	Image Minimum( const Image & in1, const Image & in2 );
	void  Minimum( const Image & in1, const Image & in2, Image & out );
	Image Minimum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   uint32_t width, uint32_t height );
	void  Minimum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	Image Subtract( const Image & in1, const Image & in2 );
	void  Subtract( const Image & in1, const Image & in2, Image & out );
	Image Subtract( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					uint32_t width, uint32_t height );
	void  Subtract( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	// Thresholding works in such way:
		// if pixel intensity on input image is          less (  < ) than threshold then set pixel intensity on output image as 0
		// if pixel intensity on input image is equal or more ( >= ) than threshold then set pixel intensity on output image as 255
	Image Threshold( const Image & in, uint8_t threshold );
	void  Threshold( const Image & in, Image & out, uint8_t threshold );
	Image Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height, uint8_t threshold );
	void  Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					 uint32_t width, uint32_t height, uint8_t threshold );
};

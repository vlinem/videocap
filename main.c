#include<stdio.h>
#include"camer.h"

#define DEVICE_NAME "/dev/video0"

#define FILE_NAME "./out.yuv"
int main(int argc,char *argv[])
{
	int ret = 0;
	int i;
	ret = open_device(DEVICE_NAME);
	if (ret == -1) 
		exit(EXIT_FAILURE);
	open_file(FILE_NAME);
	init_device();
	init_mmap();
	start_stream();

	for (i = 0 ; i < 600; i++)
	{
		process_frame();	
		printf("frame:%d\n",i);
	}

	end_stream();
	close_mmap();
	close_device();
	
	
	return 0;
}

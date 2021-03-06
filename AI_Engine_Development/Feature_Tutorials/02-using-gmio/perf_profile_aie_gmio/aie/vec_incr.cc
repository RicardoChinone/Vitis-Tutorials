/**********
© Copyright 2020 Xilinx, Inc.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********/
#include <adf.h>
void vec_incr(input_window_int32* data,output_window_int32* out){
	alignas(32) int32 const1[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	v16int32 vec1=*(v16int32*)const1;
	for(int i=0;i<16;i++)
	chess_prepare_for_pipelining
	chess_loop_range(4,)
	{
		v16int32 vdata=window_readincr_v16(data);
		v16int32 vresult=add16(vdata,vec1);
		window_writeincr(out,vresult);
	}
	unsigned long long time=get_cycles();//cycle counter of the AI Engine tile
	window_writeincr(out,time);
}

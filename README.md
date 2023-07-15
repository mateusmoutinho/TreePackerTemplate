# TreePackerTemplate
An Tree Packer template Repo

## Usage 
first you need to run **tree_creating.c** to create the **folder_data.h** witch contains all the 
tree in base64, after the **folder_data.h** were created , run **main.c** to generate the binary
with the self contained folder.


### Explanation

#### Creating the b64 tree 
The archquiteture of these packer conssist in first,convert the full folder into an DtwTree object, than transform it into json 
The Following exemple will create an json tree
~~~c

#include "dependencies/doTheWorld.h"


int main(){

    struct DtwTree *exemple_folder = newDtwTree();

    exemple_folder->add_tree_from_hardware(
            exemple_folder,
            "exemple_folder",
            &(DtwTreeProps){
                .content        = DTW_INCLUDE,
                .hadware_data   = DTW_HIDE,
                .path_atributes = DTW_HIDE,
            }
    );


    exemple_folder->dumps_json_tree_to_file(
            exemple_folder,
            "tree.json",
            &(DtwTreeProps){
                .minification   = DTW_NOT_MIMIFY,
                .content_data   = DTW_HIDE,
                .hadware_data   = DTW_HIDE,
                .path_atributes = DTW_HIDE
            }
    );
    
     exemple_folder->free(exemple_folder);
}
~~~
After  we just need to transform that json tree into an b64 const char * 
we implement it with the following code:
~~~c

    char *result = exemple_folder->dumps_json_tree(
            exemple_folder,
            &(DtwTreeProps){
                .minification   = DTW_NOT_MIMIFY,
                .content_data   = DTW_HIDE,
                .hadware_data   = DTW_HIDE,
                .path_atributes = DTW_HIDE
            }
    );
    char *inb64 = dtw_base64_encode((unsigned char *)result, strlen(result));

    char *folder_data = (char*) malloc(strlen(inb64) + 100);
    sprintf(folder_data,"const char *exemple_folder_in_base64 = \"%s\";",inb64);

    dtw_write_string_file_content("folder_data.h",folder_data);
~~~

#### Loading the b64 tree 
On the main, we need to load the b64 tree, decode it , and than implement the program
The loading occours on following part 
~~~c
    //Loading the tree ------------------------------------------------------------------
    DtwTree *exemple_folder  = newDtwTree();
    long output_size;
    unsigned  char *converted = dtw_base64_decode(exemple_folder_in_base64,&output_size);
    //whe hate to make it to reconvert to an normal string
    converted[output_size] = '\0';
    exemple_folder->loads_json_tree(exemple_folder,(char*)converted);
    free(converted);

~~~





### Dependecies and Atributions 
#### DoTheWorld
MIT License

Copyright (c) 2023 Mateus Moutinho Queiroz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


#### CliInput

MIT License

Copyright (c) 2023 WacoderForever

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
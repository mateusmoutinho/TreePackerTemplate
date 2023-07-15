//
// Created by jurandi on 20-06-2023.
//
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


    free(inb64);
    free(result);
    free(folder_data);
    exemple_folder->free(exemple_folder);
}
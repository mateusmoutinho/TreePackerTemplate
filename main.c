//
// Created by mateusmoutinho on 14/07/23.
//
#include "doTheWorld.h"
#include "folder_data.h"

DtwTree *exemple_folder = NULL;

void load_exemple_tree(){
    //to avoid loading twice
    if(exemple_folder){
        return;
    }
    exemple_folder = newDtwTree();
    long output_size;
    unsigned  char *converted = dtw_base64_decode(exemple_folderb_in_base64,&output_size);
    exemple_folder->loads_json_tree(exemple_folder,(char*)converted);
    free(converted);
}

int main(){

    load_exemple_tree();

    exemple_folder->insecure_hardware_write_tree(exemple_folder);
    

}
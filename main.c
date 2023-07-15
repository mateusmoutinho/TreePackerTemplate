//
// Created by mateusmoutinho on 14/07/23.
//
#include "dependencies/doTheWorld.h"
#include  "dependencies/cliinput.h"
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

    //exemple_folder->insecure_hardware_write_tree(exemple_folder);
    char *destination = "test/";

    //modifying the tree
    for(int i = 0 ; i <exemple_folder->size; i++){
        DtwTreePart *current_part = exemple_folder->tree_parts[i];
        DtwPath *current_path = current_part->path;
        current_path->add_start_dir(current_path,destination);
        printf("--------------------------\n");
        current_path->represent(current_path);
    }
    //exemple_folder->represent(exemple_folder);
    //exemple_folder->hardware_commit_tree(exemple_folder);
    exemple_folder->free(exemple_folder);

}
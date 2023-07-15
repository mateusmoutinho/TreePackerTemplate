//
// Created by mateusmoutinho on 14/07/23.
//
#include "dependencies/doTheWorld.h"
#include  "dependencies/cliinput.h"
#include "folder_data.h"


int main(){

    //Loading the tree ------------------------------------------------------------------
    DtwTree *exemple_folder  = newDtwTree();
    long output_size;
    unsigned  char *converted = dtw_base64_decode(exemple_folderb_in_base64,&output_size);
    exemple_folder->loads_json_tree(exemple_folder,(char*)converted);
    free(converted);

    CliInterface  interface = newCliInterface();

    char *destination =  interface.ask_string(&interface,"inform the destionation",CLI_TRIM);


    //Iterate over the tree to add the start dir
    for(int i = 0 ; i <exemple_folder->size; i++) {
        DtwTreePart *current_part = exemple_folder->tree_parts[i];
        DtwPath *current_path = current_part->path;
        current_path->add_start_dir(current_path, destination);
        current_part->hardware_write(current_part, DTW_SET_AS_ACTION);
    }

    //verifying if its to copy the folder
    DtwTreeTransactionReport *report = exemple_folder->report(exemple_folder);

    interface.print(&interface,"the foolowing transaction will be executed\n");
    report->represent(report);

    bool execute = interface.ask_option(&interface,"continue ? (yes,no)","no | yes");

    if(execute){
        //implement the modifications
        exemple_folder->hardware_commit_tree(exemple_folder);
        interface.print(&interface,"transaction executed");
    }

    else{
        interface.warning(&interface,"transacton aborted");

    }

    report->free(report);
    exemple_folder->free(exemple_folder);

}
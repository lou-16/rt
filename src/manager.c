#include "manager.h"
#include <stdlib.h>
#include <stdio.h>
#define MINIMUM_SM_CAPACITY 50

void Scenemanager_init(){
    SceneObject* ObjectVector = malloc(MINIMUM_SM_CAPACITY * sizeof(SceneObject));
    if(ObjectVector == NULL){
        printf("[+]SceneManager Initialisation failed.");
        return;
    } else {
        SM.Objects = ObjectVector;
        SM.count = 0;
        SM.capacity = MINIMUM_SM_CAPACITY;
        printf("[+]SceneManager Initialisation Successful!");
    }
    return;
}

void ScenemanagerDestroy(){
    free((void*) (SM.Objects));
    return;
};
bool addObject(SceneObject obj){
    SM.count++;
    if(SM.count + 1 > SM.capacity){
        SceneObject* newSceneVec = realloc((void*)(SM.Objects), (SM.capacity + 50));
        if(newSceneVec == NULL) {
            free(newSceneVec);
            printf("[+]SceneManager Error: Addition of Object to SceneObject Vector failed. Reallocation failure. Insufficient Memory");
            return false;
        }
        else {
            SM.Objects = newSceneVec;
            SM.capacity += 50;
        }
    }
    return true;
};
bool removeObject(int _id){
    for(int i = 0; i < SM.count; i++){
        if(SM.Objects[i].id == _id){
            SM.Objects[i].id = -1;
            SM.count -= 1;
            return true;
        }
    }
    return false;
};

SceneObject* getObject(int id) {
    for (int i = 0; i < SM.count; i++){
        if(SM.Objects[i].id == id){
            SceneObject* ret = &(SM.Objects[i]);
            return ret;
        }
    }
}

// This is only to be called periodically and will be implemented later, using 
// time based callbacks. for now, its empty
bool __cleanup_objects(){
    return true;
}
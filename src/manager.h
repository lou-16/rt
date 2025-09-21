#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <stdbool.h>
typedef enum ObjectType {
    OBJECT_LINE,
    OBJECT_CIRCLE,
    OBJECT_MESH,
    OBJECT_UNKNOWN
};

typedef struct SceneObject {
    int id;
    const char* name;
    ObjectType type;
    float x, y, z; // transform values
    void* data;
} SceneObject;

typedef struct SceneManager {
    SceneObject* Objects;
    int count;
    int capacity;
} SceneManager;

SceneManager SM;
void ScenemanagerInit();
void ScenemanagerDestroy();
bool addObject(SceneObject obj);
bool removeObject(int id);

SceneObject* getObject(int id);


#endif
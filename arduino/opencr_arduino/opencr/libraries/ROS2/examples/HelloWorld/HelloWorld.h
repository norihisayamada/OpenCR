// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file HelloWorld.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _HelloWorld_H_
#define _HelloWorld_H_

#include <string.h>
#include <stdlib.h>
#include <micrortps/client/client.h>
#include <microcdr/microcdr.h>

/*!
 * @brief This class represents the structure HelloWorld defined by the user in the IDL file.
 * @ingroup HELLOWORLD
 */
typedef struct HelloWorld
{
    uint32_t m_index;
    char* m_message;
} HelloWorld;

bool serialize_HelloWorld_topic(MicroBuffer* writer, const AbstractTopic* topic_structure)
{
    HelloWorld* topic = (HelloWorld*) topic_structure->topic;
    serialize_uint32_t(writer, topic->m_index);
    serialize_uint32_t(writer, strlen(topic->m_message) + 1);
    serialize_array_char(writer, topic->m_message, strlen(topic->m_message) + 1);

    return true;
}

bool deserialize_HelloWorld_topic(MicroBuffer* reader, AbstractTopic* topic_structure)
{
    HelloWorld* topic = malloc(sizeof(HelloWorld));
    deserialize_uint32_t(reader, &topic->m_index);
    uint32_t size = 0;
    deserialize_uint32_t(reader, &size);
    topic->m_message = malloc(size);
    deserialize_array_char(reader, topic->m_message, size);

    topic_structure->topic = topic;
    return true;
}

#endif // _HelloWorld_H_
/* file: backward_result.cpp */
/*******************************************************************************
* Copyright 2014-2016 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <jni.h>
#include "neural_networks/layers/JBackwardResultLayerDataId.h"
#include "neural_networks/layers/concat/JBackwardResult.h"

#include "daal.h"

#include "common_helpers.h"

#define resultLayerDataId com_intel_daal_algorithms_neural_networks_layers_BackwardResultLayerDataId_resultLayerDataId

using namespace daal;
using namespace daal::algorithms::neural_networks::layers::concat;
using namespace daal::algorithms::neural_networks;

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_concat_BackwardResult
 * Method:    cNewResult
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_concat_BackwardResult_cNewResult
  (JNIEnv *env, jobject thisObj)
{
    return jniArgument<backward::Result>::newObj();
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_BackwardResult
 * Method:    cGetValue
 * Signature: (JIJ)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_concat_BackwardResult_cGetValue
  (JNIEnv *env, jobject thisObj, jlong resAddr, jint id, jlong index)
{
    if (id == resultLayerDataId)
    {
        return jniArgument<backward::Result>::get<layers::backward::ResultLayerDataId, Tensor>(resAddr, id, (size_t)index);
    }

    return (jlong)0;
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_BackwardResult
 * Method:    cSetValue
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_concat_BackwardResult_cSetValue
  (JNIEnv *env, jobject thisObj, jlong resAddr, jint id, jlong ntAddr, jlong index)
{
    if (id == resultLayerDataId)
    {
        jniArgument<backward::Result>::set<layers::backward::ResultLayerDataId, Tensor>(resAddr, id, ntAddr, (size_t)index);
    }
}

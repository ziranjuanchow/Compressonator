// AMD AMDUtils code
// 
// Copyright(c) 2017 Advanced Micro Devices, Inc.All rights reserved.
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "stdafx.h"
#include "GltfTechnique.h"

void GltfTechnique::Draw(ID3D12GraphicsCommandList* pCommandList)
{
    DWORD dwNodesVisible;

    std::vector<NodeMatrixPostTransform> nodes(m_pGLTFData->GetNodeCount());
    if (nodes.size() == 0) return;
    m_pGLTFData->TransformNodes(nodes.data(), &dwNodesVisible);

    for (DWORD i = 0; i < dwNodesVisible; i++)
    {
        tfNode *pNode = nodes[i].pN;
        if (pNode != NULL && pNode->meshIndex >= 0)
        {
            DrawMesh(pCommandList, pNode->meshIndex, nodes[i].m);
        }
    }
}


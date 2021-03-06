
#include "PreComp.h"
#include "KRipper9.h"



HRESULT KRipper9::_IDirect3DDevice9_DrawIndexedPrimitiveUP(
    PFN_IDirect3DDevice9_DrawIndexedPrimitiveUP e,
    IDirect3DDevice9 *pDev, 
    D3DPRIMITIVETYPE Type, 
    UINT MinVertexIndex, 
    UINT NumVertices, 
    UINT PrimitiveCount, 
    CONST void * pIndexData, 
    D3DFORMAT IndexDataFormat, 
    CONST void* pVertexStreamZeroData, 
    UINT VertexStreamZeroStride
    )
{

    g_pIntruder->KeyHandler( this );

    DWORD RipEnabled = g_pIntruder->IsMeshRipEnabled();
    DWORD MinPrim    = g_pIntruder->GetSettings()->dwMinPrimitives;

    ::EnterCriticalSection( &cs );

    if( RipEnabled && ( PrimitiveCount >= MinPrim ) )
    {

        g_pLog->Write( L"IDirect3DDevice9_DrawIndexedPrimitiveUP( 0x%p, %d, %d, %d, %d, 0x%p, %d, 0x%p, %d )\n", 
            pDev, Type, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride );

        __try
        {
            g_pLog->Write( L"Error: Not realized\n\n" );
        }
        __except( EXCEPTION_EXECUTE_HANDLER )
        {
            g_pLog->Write( L"Error: IDirect3DDevice9_DrawIndexedPrimitiveUP() exception\n\n\n" );
        }
    }
    ::LeaveCriticalSection( &cs );
    
    return e(pDev, Type, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}


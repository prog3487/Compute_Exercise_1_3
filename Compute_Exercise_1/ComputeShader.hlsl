

StructuredBuffer<float3> gInput;

RWTexture1D<float> gOutput;

[numthreads(64, 1, 1)]
void main( uint3 DTid : SV_DispatchThreadID )
{
	gOutput[DTid.x] = length(gInput[DTid.x]);
}
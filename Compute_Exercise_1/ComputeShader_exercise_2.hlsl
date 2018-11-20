

ByteAddressBuffer gInput : register(t0);		// float3
RWByteAddressBuffer gOutput : register(u0);		// float

[numthreads(64, 1, 1)]
void main(uint3 DTid : SV_DispatchThreadID)
{
	float x = asfloat(gInput.Load(DTid.x * 12));
	float y = asfloat(gInput.Load(DTid.x * 12 + 4));
	float z = asfloat(gInput.Load(DTid.x * 12 + 8));

	float len = length(float3(x, y, z));

	gOutput.Store(DTid.x * 4, asuint(len));
}
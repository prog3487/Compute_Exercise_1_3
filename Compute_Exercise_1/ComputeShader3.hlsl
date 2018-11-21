

ConsumeStructuredBuffer<float3> gInput : register(u0);
AppendStructuredBuffer<float> gOutput : register(u1);

[numthreads(64, 1, 1)]
void main(uint3 DTid : SV_DispatchThreadID)
{
	float3 vec = gInput.Consume();
	float len = length(vec);
	gOutput.Append(len);
}

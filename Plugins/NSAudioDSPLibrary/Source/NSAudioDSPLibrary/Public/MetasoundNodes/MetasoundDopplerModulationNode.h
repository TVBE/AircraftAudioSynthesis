﻿#include "DSPProcessing/DopplerModulation.h"
#include "MetasoundEnumRegistrationMacro.h"
#include "MetasoundParamHelper.h"

namespace Metasound
{
#define LOCTEXT_NAMESPACE "MetasoundStandardNodes_DopplerModulationNode"

	namespace DopplerModulationNode
	{
		METASOUND_PARAM(InParamNameAudioInput, "In",        "Audio input.")
		METASOUND_PARAM(InParamNameModulationInput,  "Modulation", "The delay modulation signal.")
		METASOUND_PARAM(OutParamNameAudio,     "Out",       "Audio output.")
	}

#undef LOCTEXT_NAMESPACE
	class FDopplerModulationOperator : public TExecutableOperator<FDopplerModulationOperator>
	{
	public:
		static const FNodeClassMetadata& GetNodeInfo();
		static const FVertexInterface& GetVertexInterface();
		static TUniquePtr<IOperator> CreateOperator(const FCreateOperatorParams& InParams, FBuildErrorArray& OutErrors);

		FDopplerModulationOperator(
			const FOperatorSettings& InSettings,
			const FAudioBufferReadRef& InAudioInput,
			const FAudioBufferReadRef& InModulationInput); //intentionally keeping this signal as float

		virtual FDataReferenceCollection GetInputs()  const override;
		virtual FDataReferenceCollection GetOutputs() const override;

		void Execute();

	private:
		FAudioBufferReadRef  AudioInput;
		FAudioBufferReadRef ModulationInput;
		FAudioBufferWriteRef AudioOutput;

		// The internal delay buffer
		Audio::FDelay DelayBuffer;

		//The effect processor using a delay buffer.
		DSPProcessing::FDopplerModulation DopplerModulationDSPProcessor;

		//FFloatReadRef Modulation; //again keep the mod signal as float for now.
	};
	class FDopplerModulationNode : public FNodeFacade
	{
	public:
		FDopplerModulationNode(const FNodeInitData& InitData);
	};
}

// ------------------------------------------------

#include "Kaixo/ExtremeSidechain/Controller.hpp"

// ------------------------------------------------

namespace Kaixo {

    // ------------------------------------------------
    
    static constexpr float fastAbs(float v) { return v < 0 ? -v : v; }

    // ------------------------------------------------

    Controller::Controller()
        : AudioProcessor(BusesProperties()
            .withOutput("Output", juce::AudioChannelSet::stereo(), true)
            .withInput("Input", juce::AudioChannelSet::stereo(), true)
            .withInput("Sidechain", juce::AudioChannelSet::stereo(), true)
        )
    {}

    // ------------------------------------------------

    bool Controller::isBusesLayoutSupported(const BusesLayout& layouts) const {
        return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo()
            && layouts.getMainInputChannelSet() == juce::AudioChannelSet::stereo()
            && layouts.getChannelSet(true, 1) == juce::AudioChannelSet::stereo();
    }

    // ------------------------------------------------

    void Controller::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) {
        juce::ScopedNoDenormals noDenormals;

        // ------------------------------------------------

        const auto _numSamples = buffer.getNumSamples();

        float* const* _outputData = buffer.getArrayOfWritePointers();
        const float* const* _inputData = buffer.getArrayOfReadPointers();

        for (std::size_t j = 0; j < _numSamples; ++j) {
            _outputData[0][j] = _inputData[0][j] - fastAbs(_inputData[2][j]) * _inputData[0][j];
            _outputData[1][j] = _inputData[1][j] - fastAbs(_inputData[3][j]) * _inputData[1][j];
        }

        // ------------------------------------------------

    }

    // ------------------------------------------------

}

// ------------------------------------------------

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new Kaixo::Controller;
}

// ------------------------------------------------

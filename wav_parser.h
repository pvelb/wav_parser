/**
	\file wav_parser.h
	\brief wav_parser header file

	\author PBabak
	\version 1.0
	\date Dec 29, 2021

	There are function prototypes and file header structure
 */

#ifndef SRC_WAV_PARSER_H_
#define SRC_WAV_PARSER_H_

/**
  \brief File header structure


 */
typedef struct {
	char riff[4];			///< Contains the letters "RIFF" in ASCII form
	uint32_t fileSize;		///< This is the size of the entire file in bytes minus 8 bytes for the two fields not included in this count:ChunkID and ChunkSize.
	char fyleType[4];		///< Contains the letters "WAVE" (0x57415645 big-endian form).
	char chunkMarker[4];	///< Contains the letters "fmt " (0x666d7420 big-endian form).
	uint32_t lenFmtData;	///< 16 for PCM.  This is the size of the rest of the Subchunk which follows this number.
	uint16_t fmtType;		///< PCM = 1 (i.e. Linear quantization) Values other than 1 indicate some form of compression.
	uint16_t chNumb;		///< Mono = 1, Stereo = 2, etc.
	uint32_t sampleRate;	///< 8000, 44100, etc.
	uint32_t byteRate;		///< == SampleRate * NumChannels * BitsPerSample/8
	uint16_t bytesPerSample;///< == NumChannels * BitsPerSample/8 The number of bytes for one sample including all channels.
	uint16_t bitsPerSample;	///< 8 bits = 8, 16 bits = 16, etc.
	char datChunkHeader[4];	///< Contains the letters "data" (0x64617461 big-endian form).
	uint32_t dataSize;		///< == NumSamples * NumChannels * BitsPerSample/8 This is the number of bytes in the data.

} WavHeaderTypeDef;
extern const uint8_t wavFileData[];

void wavPrintHeader(WavHeaderTypeDef* file);
int wav2csv(WavHeaderTypeDef* file, char* csv);
#endif /* SRC_WAV_PARSER_H_ */

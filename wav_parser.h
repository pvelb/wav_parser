/*
 * wav_parser.h
 *
 *  Created on: Dec 29, 2021
 *      Author: power
 */

#ifndef SRC_WAV_PARSER_H_
#define SRC_WAV_PARSER_H_


typedef struct {
	char riff[4];
	uint32_t fileSize;
	char fyleType[4];
	char chunkMarker[4];
	uint32_t lenFmtData;
	uint16_t fmtType;
	uint16_t chNumb;
	uint32_t sampleRate;
	uint32_t byteRate;
	uint16_t bytesPerSample;
	uint16_t bitsPerSample;
	char datChunkHeader[4];
	uint32_t dataSize;
} WavHeaderTypeDef;
extern const uint8_t wavFileData[];

void wavPrintHeader(WavHeaderTypeDef* file);
int wav2csv(WavHeaderTypeDef* file, char* csv);
#endif /* SRC_WAV_PARSER_H_ */

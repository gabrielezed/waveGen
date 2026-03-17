#ifndef GENJAGGEDARR_H
#define GENJAGGEDARR_H

#include "genDynArr.h"

#define DEFINE_JAGGEDARR(T, RowName, MatName) \
	DEFINE_DYNARR(T, RowName) \
	\
	DEFINE_DYNARR(RowName, MatName) \
	\
	static inline void MatName##_push_at(MatName* mat, size_t row_idx, T val){ \
		while(mat->len <= row_idx){ \
			RowName new_row; \
			RowName##_init(&new_row); \
			MatName##_push(mat, new_row); \
		} \
		RowName##_push(&mat->data[row_idx], val); \
	} \
	\
	static inline void MatName##_deep_free(MatName* mat){ \
		for(size_t i = 0; i < mat->len; i++){ \
			RowName##_free(&mat->data[i]); \
		} \
		MatName##_free(mat); \
	}

#endif
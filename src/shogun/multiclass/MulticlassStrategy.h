/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2012 Chiyuan Zhang
 * Copyright (C) 2012 Chiyuan Zhang
 */

#ifndef MULTICLASSSTRATEGY_H__
#define MULTICLASSSTRATEGY_H__

#include <shogun/base/SGObject.h>
#include <shogun/features/Labels.h>
#include <shogun/features/RejectionStrategy.h>

namespace shogun
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
enum EMulticlassStrategy
{
	ONE_VS_REST_STRATEGY,
	ONE_VS_ONE_STRATEGY,
};
#endif

class CMulticlassStrategy: public CSGObject
{
public:
	/** constructor */
	CMulticlassStrategy();

	/** destructor */
	virtual ~CMulticlassStrategy() {}

	/** get name */
	virtual const char* get_name() const
	{
		return "MulticlassStrategy";
	};

	/** get strategy type */
	virtual EMulticlassStrategy get_strategy_type()=0;

	/** start training */
	virtual void train_start(CLabels *orig_labels, CLabels *train_labels);

	/** has more training phase */
	virtual bool train_has_more()=0;

	/** prepare for the next training phase.
	 * @return The subset that should be applied. Return NULL when no subset is needed.
	 */
	virtual SGVector<int32_t> train_prepare_next();

	/** finish training, release resources */
	virtual void train_stop();

	/** decide the final label.
	 * @param outputs a vector of output from each machine (in that order)
	 * @param num_classes number of classes
	 */
	virtual int32_t decide_label(const SGVector<float64_t> &outputs, int32_t num_classes)=0;

	/** get number of machines used in this strategy.
	 * @param num_classes number of classes in this problem
	 */
	virtual int32_t get_num_machines(int32_t num_classes)=0;

protected:
	CLabels *m_train_labels;
	CLabels *m_orig_labels;
	int32_t m_train_iter;
};

} // namespace shogun

#endif /* end of include guard: MULTICLASSSTRATEGY_H__ */


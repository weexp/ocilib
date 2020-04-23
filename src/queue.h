/*
 * OCILIB - C Driver for Oracle (C Wrapper for Oracle OCI)
 *
 * Website: http://www.ocilib.net
 *
 * Copyright (c) 2007-2020 Vincent ROGIER <vince.rogier@ocilib.net>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#ifndef OCILIB_QUEUE_H_INCLUDED
#define OCILIB_QUEUE_H_INCLUDED

#include "types.h"

boolean QueueCreate
(
    OCI_Connection  *con,
    const otext *queue_name,
    const otext *queue_table,
    unsigned int queue_type,
    unsigned int max_retries,
    unsigned int retry_delay,
    unsigned int retention_time,
    boolean      dependency_tracking,
    const otext *comment
);

boolean QueueAlter
(
    OCI_Connection  *con,
    const otext *queue_name,
    unsigned int max_retries,
    unsigned int retry_delay,
    unsigned int retention_time,
    const otext *comment
);

boolean QueueDrop
(
    OCI_Connection  *con,
    const otext *queue_name
);

boolean QueueStart
(
    OCI_Connection  *con,
    const otext *queue_name,
    boolean      enqueue,
    boolean      dequeue
);

boolean QueueStop
(
    OCI_Connection  *con,
    const otext *queue_name,
    boolean      enqueue,
    boolean      dequeue,
    boolean      wait
);

boolean QueueTableCreate
(
    OCI_Connection  *con,
    const otext *queue_table,
    const otext *queue_payload_type,
    const otext *storage_clause,
    const otext *sort_list,
    boolean      multiple_consumers,
    unsigned int message_grouping,
    const otext *comment,
    unsigned int primary_instance,
    unsigned int secondary_instance,
    const otext *compatible
);

boolean QueueTableAlter
(
    OCI_Connection  *con,
    const otext *queue_table,
    const otext *comment,
    unsigned int primary_instance,
    unsigned int secondary_instance
);

boolean QueueTableDrop
(
    OCI_Connection  *con,
    const otext *queue_table,
    boolean      force
);

boolean QueueTablePurge
(
    OCI_Connection  *con,
    const otext *queue_table,
    const otext *purge_condition,
    boolean      block,
    unsigned int delivery_mode
);

boolean QueueTableMigrate
(
    OCI_Connection  *con,
    const otext *queue_table,
    const otext *compatible
);

#endif /* OCILIB_QUEUE_H_INCLUDED */

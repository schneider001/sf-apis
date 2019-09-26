#!/usr/bin/env python3
#
# Copyright (C) 2019 IBM Corporation.
#
# Authors:
# Teryl Taylor <terylt@ibm.com>
# Frederico Araujo <frederico.araujo@ibm.com>
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
import sysflow.opflags as opflags
from datetime import datetime

"""
.. module:: sysflow.utils
   :synopsis: Utility functions to help transform attributes into strings. 
.. moduleauthor:: Teryl Taylor, Frederico Araujo
"""

NANO_TO_SECS = 1000000000
TIME_FORMAT = "%m/%d/%YT%H:%M:%S.%f"

def getOpFlagsStr(opFlags):
    """
       Converts a sysflow operations flag bitmap into a string representation.
       
       :param opflag: An operations bitmap from a flow or event.
       :type opflag: int
        
       :rtype: str
       :return: A string representation of the operations bitmap.
    """
    ops = ""
    ops +=  "MKDIR" if (opFlags & opflags.OP_MKDIR) else "";
    ops +=  "RMDIR" if (opFlags & opflags.OP_RMDIR) else "";
    ops +=  "LINK" if (opFlags & opflags.OP_LINK) else "";
    ops +=  "SYMLINK" if (opFlags & opflags.OP_SYMLINK) else  "";
    ops +=  "UNLINK" if (opFlags & opflags.OP_UNLINK) else  "";
    ops +=  "RENAME" if (opFlags & opflags.OP_RENAME) else  "";

    if(len(ops) > 0):
        return ops
    
    ops +=  "CLONE" if (opFlags & opflags.OP_CLONE) else "";
    ops +=  "EXEC" if (opFlags & opflags.OP_EXEC) else "";
    ops +=  "EXIT" if (opFlags & opflags.OP_EXIT) else "";
    ops +=  "SETUID" if (opFlags & opflags.OP_SETUID) else  "";
    
    if(len(ops) > 0):
        return ops

    ops +=  "O" if (opFlags & opflags.OP_OPEN) else  " ";
    ops +=  "A" if (opFlags & opflags.OP_ACCEPT) else " ";
    ops +=  "C" if (opFlags & opflags.OP_CONNECT) else  " ";
    ops +=  "W" if (opFlags & opflags.OP_WRITE_SEND)  else " ";
    ops +=  "R" if (opFlags & opflags.OP_READ_RECV)  else " ";
    ops +=  "N" if (opFlags & opflags.OP_SETNS)  else " ";
    ops +=  "M" if (opFlags & opflags.OP_MMAP)  else " ";
    ops +=  "S" if (opFlags & opflags.OP_SHUTDOWN)  else " ";
    ops +=  "C" if (opFlags & opflags.OP_CLOSE)  else " ";
    ops +=  "T" if (opFlags & opflags.OP_TRUNCATE) else " ";
    ops +=  "D" if (opFlags & opflags.OP_DIGEST)  else " ";
    return ops

def getTimeStr(ts):
    """
       Converts a nanosecond ts into a string representation.
       
       :param ts: A nanosecond epoch.
       :type ts: int
        
       :rtype: str
       :return: A string representation of the timestamp in %m/%d/%YT%H:%M:%S.%f format.
    """
    tStamp = datetime.fromtimestamp(float(float(ts)/NANO_TO_SECS))
    timeStr = tStamp.strftime(TIME_FORMAT)
    return timeStr

def getNetFlowStr(nf):
    """
       Converts a NetworkFlow into a string representation.
       
       :param nf: a NetworkFlow object.
       :type nf: sysflow.schema_classes.SchemaClasses.sysflow.flow.NetworkFlowClass
        
       :rtype: str
       :return: A string representation of the NetworkFlow in form (sip:sport-dip:dport).
    """
    sip = ".".join(map(lambda n: str(nf.sip>>n & 0xFF), [0, 8, 16, 24]))
    dip = ".".join(map(lambda n: str(nf.dip>>n & 0xFF), [0, 8, 16, 24]))
    return str(sip) + ":" + str(nf.sport) + "-" + str(dip) + ":" + str(nf.dport)  


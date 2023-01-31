#ifndef __AVSC_SYSFLOW5
#define __AVSC_SYSFLOW5
#include <string>
extern const std::string AVSC_SF = "{\n  \"type\" : \"record\",\n  \"name\" : \"SysFlow\",\n  \"namespace\" : \"sysflow\",\n  \"fields\" : [ {\n    \"name\" : \"rec\",\n    \"type\" : [ {\n      \"type\" : \"record\",\n      \"name\" : \"SFHeader\",\n      \"namespace\" : \"sysflow.entity\",\n      \"fields\" : [ {\n        \"name\" : \"version\",\n        \"type\" : \"long\",\n        \"default\" : 5\n      }, {\n        \"name\" : \"exporter\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"ip\",\n        \"type\" : \"string\",\n        \"default\" : \"NA\"\n      }, {\n        \"name\" : \"filename\",\n        \"type\" : \"string\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"Container\",\n      \"namespace\" : \"sysflow.entity\",\n      \"fields\" : [ {\n        \"name\" : \"id\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"name\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"image\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"imageid\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"type\",\n        \"type\" : {\n          \"type\" : \"enum\",\n          \"name\" : \"ContainerType\",\n          \"namespace\" : \"sysflow.type\",\n          \"symbols\" : [ \"CT_DOCKER\", \"CT_LXC\", \"CT_LIBVIRT_LXC\", \"CT_MESOS\", \"CT_RKT\", \"CT_CUSTOM\", \"CT_CRI\", \"CT_CONTAINERD\", \"CT_CRIO\", \"CT_BPM\" ]\n        }\n      }, {\n        \"name\" : \"privileged\",\n        \"type\" : \"boolean\"\n      }, {\n        \"name\" : \"podId\",\n        \"type\" : [ \"null\", \"string\" ]\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"Process\",\n      \"namespace\" : \"sysflow.entity\",\n      \"fields\" : [ {\n        \"name\" : \"state\",\n        \"type\" : {\n          \"type\" : \"enum\",\n          \"name\" : \"SFObjectState\",\n          \"namespace\" : \"sysflow.type\",\n          \"symbols\" : [ \"CREATED\", \"MODIFIED\", \"REUP\" ]\n        }\n      }, {\n        \"name\" : \"oid\",\n        \"type\" : {\n          \"type\" : \"record\",\n          \"name\" : \"OID\",\n          \"namespace\" : \"sysflow.type\",\n          \"fields\" : [ {\n            \"name\" : \"createTS\",\n            \"type\" : \"long\"\n          }, {\n            \"name\" : \"hpid\",\n            \"type\" : \"long\"\n          } ]\n        }\n      }, {\n        \"name\" : \"poid\",\n        \"type\" : [ \"null\", \"sysflow.type.OID\" ]\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"exe\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"exeArgs\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"cwd\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"uid\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"userName\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"gid\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"groupName\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"tty\",\n        \"type\" : \"boolean\"\n      }, {\n        \"name\" : \"containerId\",\n        \"type\" : [ \"null\", \"string\" ]\n      }, {\n        \"name\" : \"entry\",\n        \"type\" : \"boolean\",\n        \"default\" : false\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"File\",\n      \"namespace\" : \"sysflow.entity\",\n      \"fields\" : [ {\n        \"name\" : \"state\",\n        \"type\" : \"sysflow.type.SFObjectState\"\n      }, {\n        \"name\" : \"oid\",\n        \"type\" : {\n          \"type\" : \"fixed\",\n          \"name\" : \"FOID\",\n          \"namespace\" : \"sysflow.type\",\n          \"size\" : 20\n        }\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"restype\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"path\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"containerId\",\n        \"type\" : [ \"null\", \"string\" ]\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"ProcessEvent\",\n      \"namespace\" : \"sysflow.event\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"tid\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"args\",\n        \"type\" : {\n          \"type\" : \"array\",\n          \"items\" : \"string\"\n        }\n      }, {\n        \"name\" : \"ret\",\n        \"type\" : \"int\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"NetworkFlow\",\n      \"namespace\" : \"sysflow.flow\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"tid\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"endTs\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"sip\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"sport\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"dip\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"dport\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"proto\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"fd\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"numRRecvOps\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numWSendOps\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numRRecvBytes\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numWSendBytes\",\n        \"type\" : \"long\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"FileFlow\",\n      \"namespace\" : \"sysflow.flow\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"tid\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"openFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"endTs\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"fileOID\",\n        \"type\" : \"sysflow.type.FOID\"\n      }, {\n        \"name\" : \"fd\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"numRRecvOps\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numWSendOps\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numRRecvBytes\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numWSendBytes\",\n        \"type\" : \"long\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"FileEvent\",\n      \"namespace\" : \"sysflow.event\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"tid\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"fileOID\",\n        \"type\" : \"sysflow.type.FOID\"\n      }, {\n        \"name\" : \"ret\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"newFileOID\",\n        \"type\" : [ \"null\", \"sysflow.type.FOID\" ]\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"NetworkEvent\",\n      \"namespace\" : \"sysflow.event\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"tid\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"sip\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"sport\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"dip\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"dport\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"proto\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"ret\",\n        \"type\" : \"int\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"ProcessFlow\",\n      \"namespace\" : \"sysflow.flow\",\n      \"fields\" : [ {\n        \"name\" : \"procOID\",\n        \"type\" : \"sysflow.type.OID\"\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numThreadsCloned\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"opFlags\",\n        \"type\" : \"int\"\n      }, {\n        \"name\" : \"endTs\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numThreadsExited\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"numCloneErrors\",\n        \"type\" : \"long\"\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"Pod\",\n      \"namespace\" : \"sysflow.entity\",\n      \"fields\" : [ {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"id\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"name\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"nodeName\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"hostIP\",\n        \"type\" : {\n          \"type\" : \"array\",\n          \"items\" : \"long\",\n          \"logicalType\" : \"ipaddr\"\n        }\n      }, {\n        \"name\" : \"internalIP\",\n        \"type\" : {\n          \"type\" : \"array\",\n          \"items\" : \"long\",\n          \"logicalType\" : \"ipaddr\"\n        }\n      }, {\n        \"name\" : \"namespace\",\n        \"type\" : \"string\"\n      }, {\n        \"name\" : \"restartCount\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"labels\",\n        \"type\" : {\n          \"type\" : \"map\",\n          \"values\" : \"string\"\n        }\n      }, {\n        \"name\" : \"selectors\",\n        \"type\" : {\n          \"type\" : \"map\",\n          \"values\" : \"string\"\n        }\n      }, {\n        \"name\" : \"services\",\n        \"type\" : {\n          \"type\" : \"array\",\n          \"items\" : {\n            \"type\" : \"record\",\n            \"name\" : \"Service\",\n            \"fields\" : [ {\n              \"name\" : \"name\",\n              \"type\" : \"string\"\n            }, {\n              \"name\" : \"id\",\n              \"type\" : \"string\"\n            }, {\n              \"name\" : \"namespace\",\n              \"type\" : \"string\"\n            }, {\n              \"name\" : \"portList\",\n              \"type\" : {\n                \"type\" : \"array\",\n                \"items\" : {\n                  \"type\" : \"record\",\n                  \"name\" : \"Port\",\n                  \"fields\" : [ {\n                    \"name\" : \"port\",\n                    \"type\" : \"int\"\n                  }, {\n                    \"name\" : \"targetPort\",\n                    \"type\" : \"int\"\n                  }, {\n                    \"name\" : \"nodePort\",\n                    \"type\" : \"int\"\n                  }, {\n                    \"name\" : \"proto\",\n                    \"type\" : \"string\"\n                  } ]\n                }\n              }\n            }, {\n              \"name\" : \"clusterIP\",\n              \"type\" : {\n                \"type\" : \"array\",\n                \"items\" : \"long\",\n                \"logicalType\" : \"ipaddr\"\n              }\n            } ]\n          }\n        }\n      } ]\n    }, {\n      \"type\" : \"record\",\n      \"name\" : \"K8sEvent\",\n      \"namespace\" : \"sysflow.event\",\n      \"fields\" : [ {\n        \"name\" : \"kind\",\n        \"type\" : {\n          \"type\" : \"enum\",\n          \"name\" : \"K8sComponent\",\n          \"namespace\" : \"sysflow.type\",\n          \"symbols\" : [ \"K8S_NODES\", \"K8S_NAMESPACES\", \"K8S_PODS\", \"K8S_REPLICATIONCONTROLLERS\", \"K8S_SERVICES\", \"K8S_EVENTS\", \"K8S_REPLICASETS\", \"K8S_DAEMONSETS\", \"K8S_DEPLOYMENTS\", \"K8S_UNKNOWN\" ]\n        }\n      }, {\n        \"name\" : \"action\",\n        \"type\" : {\n          \"type\" : \"enum\",\n          \"name\" : \"K8sAction\",\n          \"namespace\" : \"sysflow.type\",\n          \"symbols\" : [ \"K8S_COMPONENT_ADDED\", \"K8S_COMPONENT_MODIFIED\", \"K8S_COMPONENT_DELETED\", \"K8S_COMPONENT_ERROR\", \"K8S_COMPONENT_NONEXISTENT\", \"K8S_COMPONENT_UNKNOWN\" ]\n        }\n      }, {\n        \"name\" : \"ts\",\n        \"type\" : \"long\"\n      }, {\n        \"name\" : \"message\",\n        \"type\" : \"string\"\n      } ]\n    } ]\n  } ]\n}\n";
#endif

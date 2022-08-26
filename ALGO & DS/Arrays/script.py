

list = [
	'LS_SWG',
	'LS_HTTP',
	'LS_TCP',
	'LS_ICAEVENT',
	'LS_ICAUPDATE',
	'LS_ICAAPP',
	'LS_VPN',
	'LS_NGSUSAGE',
	'LS_APPFWCONFIG',
	'LS_APPFW',
	'LS_VIDEOOPT',
	'LS_BURST_CQA',
	'LS_SLA',
	'LS_BOT',
	'LS_NGS_GI',
	'LS_MONGO',
	'LS_BOT_LE',
	'LS_MQTT',
	'LS_NGS',
	'LS_BOT_KM',
	'LS_AS_FDI',
	'LS_NGS_SLI',
	'LS_HTTP_BODY_EXPORT',
	'AF_LAST_PROTOCOL_INDEX'
]

marker_list = []
for item in list:
    item = item.lstrip('LS').lstrip('_')
    marker_list.append(item+'_DATA_STRAT')
    marker_list.append(item+'_DATA_END')
    
    marker_list.append(item+'_INT_DATA_STRAT')
    marker_list.append(item+'_INT_DATA_END')
    
    marker_list.append(item+'_STR_DATA_STRAT')
    marker_list.append(item+'_STR_DATA_END')
    
    marker_list.append(item+'_RECTYPE_STRAT')
    marker_list.append(item+'_RECTYPE_END')
    
print(marker_list)
    
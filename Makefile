all:	RPeakAlgo baseline_mean firfilter_bandpass firfilter_bandstop
RPeakAlgo:
	gcc RPeakAlgo.c -o RPeakAlgo
baseline_mean:
	gcc baseline_mean.c -o baseline_mean
firfilter_bandpass:
	gcc firfilter_bandpass.c -o firfilter_bandpass -lm
firfilter_bandstop:
	gcc firfilter_bandstop.c -o firfilter_bandstop -lm
clean:
	rm -f RPeakAlgo
	rm -f baseline_mean
	rm -f firfilter_bandpass
	rm -f firfilter_bandstop

      var contextClass = (window.AudioContext ||
        window.webkitAudioContext ||
        window.mozAudioContext ||
        window.oAudioContext ||
        window.msAudioContext);

      if (contextClass) {
        // Web Audio API is available.
        var context = new contextClass();
      }

      var oscillator1, oscillator2;

      var dialTone = function(freq1, freq2){

        // merger = context.createChannelMerger(2);

        oscillator1 = context.createOscillator();
        oscillator1.type = 0;
        oscillator1.frequency.value = freq1;
        gainNode = context.createGain ? context.createGain() : context.createGainNode();
        oscillator1.connect(gainNode,0,0);
        gainNode.connect(context.destination);
        gainNode.gain.value = .1;
        oscillator1.start ? oscillator1.start(0) : oscillator1.noteOn(0)

        // gainNode.connect(merger,0,1);

        oscillator2 = context.createOscillator();
        oscillator2.type = 0;
        oscillator2.frequency.value = freq2;
        gainNode = context.createGain ? context.createGain() : context.createGainNode();
        oscillator2.connect(gainNode);
        gainNode.connect(context.destination);
        // gainNode.connect(merger,0,0);


        gainNode.gain.value = .1;
        oscillator2.start ? oscillator2.start(0) : oscillator2.noteOn(0)

        // merger.connect(context.destination);


      };

      function start() {
        if (typeof oscillator1 != 'undefined') oscillator1.disconnect();
        if (typeof oscillator2 != 'undefined') oscillator2.disconnect();
        oscOn(parseFloat(document.getElementById("freq").value),parseFloat(document.getElementById("freq2").value));
      }


      function stop() {
        oscillator1.disconnect();
        oscillator2.disconnect();
      }

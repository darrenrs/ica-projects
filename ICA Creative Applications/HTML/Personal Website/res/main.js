let defaultFonts = {
  "body": "\"Helvetica Neue\", Helvetica, Arial, sans-serif",
  "mono": "monospace"
}

/*
  void $(HTMLElement).ready()

  Executes on jQuery load.
  Activates dark mode, query length event listener, and sets date modified.
*/
$(document).ready(function() {
    if (window.location.protocol != 'https:') {
        location.href = 'https:' + window.location.href.substring(window.location.protocol.length);
    }

    $('#drs-search-google').on('keyup', function() {
      setSearchQueryLength(getSearchQueryLength());
    });

    $('#drs-darkmode-button').on('click', function() {
      toggleDarkMode(false);
    });

    $('#drs-fontchg-body-dlfont').on('click', function() {
      getFont(0, 0)
    });

    $('#drs-fontchg-mono-dlfont').on('click', function() {
      getFont(1, 0)
    });

    $('#drs-fontchg-body-rfont').on('click', function() {
      localStorage.removeItem('font-body')
      window.location.reload()
    });

    $('#drs-fontchg-mono-rfont').on('click', function() {
      localStorage.removeItem('font-mono')
      window.location.reload()
    });

    $('#drs-resetdata').on('click', function() {
      if (confirm('Are you certain? The page will reload with default settings.')) {
        localStorage.clear()
        window.location.reload()
      }
    });

    if (localStorage.getItem('dm') === null) {
      localStorage.setItem('dm', false);
    } else if (localStorage.getItem('dm') == 'true') {
      toggleDarkModeHtml(true);
    }

    if (localStorage.getItem('font-body') === null) {
      localStorage.setItem('font-body', defaultFonts['body'])
    } else {
      if (!(localStorage.getItem('font-body') == defaultFonts['body'])) {
        getFont(0, localStorage.getItem('font-body'))
      }
    }

    if (localStorage.getItem('font-mono') === null) {
      localStorage.setItem('font-mono', defaultFonts['mono'])
    } else {
      if (!(localStorage.getItem('font-mono') == defaultFonts['mono'])) {
        getFont(1, localStorage.getItem('font-mono'))
      }
    }

    getModifiedDate();
});

/*
  void int getSearchQueryLength()

  Returns the length of the inputted Google search query.
*/
function getSearchQueryLength() {
  return $('#drs-search-google').val().length
}

/*
  void setSearchQueryLength(int len)

  Sets the query length tracker to an integer len.
*/
function setSearchQueryLength(len) {
  $('#drs-search-google-len').text(len)
}

/*
  void toggleDarkMode()

  Toggles dark mode, and calls the CSS toggler function toggleDarkModeHtml().
*/
function toggleDarkMode() {
  if (localStorage.getItem('dm') == 'false') {
    localStorage.setItem("dm", 'true')
    toggleDarkModeHtml(true)
  } else {
    localStorage.setItem("dm", 'false')
    toggleDarkModeHtml(false)
  }
}

/*
  void toggleDarkModeHtml()

  Directly toggles dark elements to light/white elements, and vice versa.
*/
function toggleDarkModeHtml(dm) {
  if (dm) {
    var state = "enabled"
  } else {
    var state = "disabled"
  }

  $('body').toggleClass('bg-white bg-dark text-light text-dark');
  $('.jumbotron, .modal-content').toggleClass('bg-light bg-dark text-light text-dark');
  $('.navbar').toggleClass('navbar-light navbar-dark bg-light bg-dark text-light text-dark');
  $('.drs-dm-target').toggleClass('btn-outline-light btn-outline-dark text-light text-dark')
  $('input').toggleClass('bg-light bg-dark text-light text-dark');
  $('table').toggleClass('table-light table-dark')
  
  $('#drs-darkmode-button').text(`Dark Mode: ${state}`)
  $('#drs-darkmode-button').attr('disabled','disabled')
  setTimeout(function() {
    $('#drs-darkmode-button').removeAttr('disabled')
  },500)
}

/*
  void getFont( int i, bool f )

  Gets the specified font from Google Fonts.
  If i is 0, act on the body font. If i is 1, act on the monospace font.
  If f is a font, assume it exists and download it. If f is false, check the font's existence first.
*/
function getFont(i, f=false) {
  var target;
  var eltgt;
  var tfont;
  var url;

  if (!i) {
    target = 'body'
    eltgt = ':not(code):not(kbd)'
  } else {
    target = 'mono'
    eltgt = 'code, kbd'
  }

  if (f) {
    tfont = f
    setFont(target, tfont, eltgt, `https://fonts.googleapis.com/css?family=${tfont}`)
  } else {
    tfont = $(`#drs-fontchg-${target}`).val().trim()

    url = `https://fonts.googleapis.com/css?family=${tfont}`

    $.ajax({
      url: url,
      dataType: "text",
      success: function(xhr) {
        setFont(target, tfont, eltgt, url)
      },
      error: function(xhr) {
        let pv = $(`#drs-fontchg-${target}-ex`).text()

        $(`#drs-fontchg-${target}-ex`).text(`Unavailable!`)
        setTimeout(function() {
          $(`#drs-fontchg-${target}-ex`).text(pv)
        }, 1000)

        console.error(xhr)
      }
    })
  }
}

/*
  void setFont( str target, str tfont, str eltgt, str url )

  Activates a new font.
  target is either body or mono.
  tfont is the font name.
  eltgt is the css selector.
  url is the URL of the font.
*/
function setFont(target, tfont, eltgt, url) {
  var tfont_number;
  localStorage.setItem(`font-${target}`, tfont)

  if (tfont.indexOf(':') != -1) {
    tfont_number = `(${tfont.substring(tfont.indexOf(':'))})`
    tfont = tfont.substring(0,tfont.indexOf(':'))
  } else {
    tfont_number = ''
  }

  $(`#drs-fontchg-${target}-stysh`).remove()
  $(`#drs-fontchg-${target}-style`).remove()

  $(`#drs-fontchg-${target}-ex`).text(`Font: ${tfont} ${tfont_number}`)
  
  $('head').append(`<link id="drs-fontchg-${target}-stysh" href="${url}" rel="stylesheet">`)
  $('head').append(`<style id="drs-fontchg-${target}-style">${eltgt} {font-family: "${tfont}" !important}</style>`)
}

/*
  void getModifiedDate()

  Sets the "Last modified: %d" string to an ISO 8601-compliant date. 
*/
function getModifiedDate() {
  $.ajax({
    url: "/last-updated",
    dataType: "text",
    success: function(xhr) {
      let d = new Date(xhr)
      if (d == "Invalid Date") {
        console.warn(`"${d}" invalid date"`)
        $("#drs-date-modified").text("invalid date")
      } else {
        $('#drs-date-modified').text(d.toLocaleString("en-US", {timeZone: "America/Denver"}))
      }
    },
    error: function(xhr) {
      $('#drs-date-modified').text('network error')
      
      console.error(xhr)
    }
  })
}
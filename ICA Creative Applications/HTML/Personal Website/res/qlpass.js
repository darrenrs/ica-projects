/*
  void $(HTMLElement).ready()

  Executes on jQuery load.
  Creates event listener for the password form.
*/
$(document).ready(function() {
    $('#drs-qlp-passwd').focus()
    $('#drs-qlp-passwd-button').on('click', function() {
      qlPassAuth();
    });
});

// This is the MD5 hash, *not* the password. Keep trying ...
var qlPassHash = 'c001fe2860babe149777726bed5e7b02'

/*
  void qlPassAuth()

  Verifies that the password is correct.
*/
function qlPassAuth() {
  if (md5( $("#drs-qlp-passwd").val() ) == qlPassHash) {
    $('#drs-qlp-status').removeClass('text-danger').addClass('text-success').html('Correct password, please wait ... <code>GET /ql/qlpc</code>')
    qlPass()
  } else {
    $('#drs-qlp-status').text('Incorrect password')
  }
}

/*
  void qlPass()

  Downloads base64 source code for quick links and decrypts it.
*/
function qlPass() {
  $.ajax({
    // Check this URL; maybe it will be the key?
    url: "/ql/qlpc",
    dataType: "text",
    success: function(xhr) {
      let decrypted = atob(xhr)

      $('#drs-qlp-pseudoform').remove()
      $('#drs-qlp-holder').html(decrypted)
    },
    error: function(xhr) {
      $('#drs-qlp-status').text('Network error')
      
      console.error(xhr)
    }
  })
}
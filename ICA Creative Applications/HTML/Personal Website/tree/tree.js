var tree = $(`<ul></ul>`)
var mimeTypes = {
  "dir": "Directory",
  "text/plain": "Text",
  "text/html": "HTML Markup",
  "text/css": "CSS Markup",
  "text/javascript": "JavaScript",
  "text/json": "JSON",
  "text/base64": "base64 Text", 
  "image/png": "PNG Image",
  "image/jpeg": "JPG Image",
  "image/x-icon": "Icon",
  "video/mp4": "MP4 Video"
}

$(document).ready(function() {
  getFileData()
});

function processFileData(data) {
  getChildren(data, tree, '')

  $('#tree').html(tree)
}

function getChildren(node, html, path) {
  setTimeout(function() {
    if (node.children) {
      path += `${node.name}/`

      let li = getFileInf(node, path)
      let ul = $(`<ul></ul>`)
      node.children.forEach(function(nc) {
          getChildren(nc, ul, path)
          html.append(li.append(ul))
      });
    } else {
      path += node.name

      let li = getFileInf(node, path)
      html.append(li)
    }

  },100)
}

function getFileInf(node, path) {
  let name = node.name;
  let type = node.mimeType;
  let size = node.size;

  let x_name;
  let x_type;
  let x_size;
  let x_tsh;

  if (type == 'dir') {
    x_name = `<strong><a href="${path}">${name}/</a></strong>`
    x_size = ``;
  } else {
    x_name = `<a href="${path}">${name}</a>`
    x_size = `; <code>${fileSizeString(size)}</code>`;
  }

  x_type = convMimeType(type);
  x_tsh = `<small>${x_type}${x_size}</small>`
  
  return $(`<li class="${ (name == "" ? "root" : "") }">${x_name} ${x_tsh}</li>`)
}

function convMimeType(mimeType) {
  if (mimeTypes[mimeType]) {
    return mimeTypes[mimeType]
  } else {
    return "Unknown"
  }
}

function fileSizeString(bytes) {
  let sfx = ['YB', 'ZB', 'EB', 'PB', 'TB', 'GB', 'MB', 'kB'];
  let pwr = Math.floor(Math.log10(bytes));

  if (bytes >= 1e27 || bytes == 0 || typeof bytes != "number") {
    return bytes
  } else if (bytes < 1e3) {
    return `${bytes} bytes`
  } else { 
    let nb = bytes / 1000**(Math.floor((Math.log(bytes) / Math.log(1000))))
    return `${nb.toFixed(2)} ${sfx[8-Math.floor(pwr/3)]}`
  }
}

function getFileData() {
  $.ajax({
    url: "/tree/tree-data",
    dataType: "json",
    success: function(xhr) {
      processFileData(xhr)
    },
    error: function(xhr) {
      console.error(xhr)
    }
  })
}
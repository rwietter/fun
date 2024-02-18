## Screen Reader Only (SRO)

> This is a technique for creating additional texts about contexts that only appear to screen readers.

---

### CSS

```css
.sr-only {
  position: absolute;
  left: -10000px;
  top: 0;
  width: 1px;
  height: 1px;
  overflow: hidden;
}
```

---

### HTML

```html
<ul>
  <li>
    <a href="...">
      <i class="google" aria-hidden="true">
      <span class="sr-only">Login com Google</span>
    </a>
  </li>
  <li>
    <a href="...">
      <i class="facebook" aria-hidden="true">
      <span class="sr-only">Login com Facebook</span>
    </a>
  </li>
  <li>
    <a href="...">
      <i class="twitter" aria-hidden="true">
      <span class="sr-only">Login com Twitter</span>
    </a>
  </li>
</ul>
```

---

### Example:

<img src="./assets/sro.png" alt="login icon context to apply screen reader only">
